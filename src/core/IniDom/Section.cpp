/*
 * Copyright (C) 2020-2021 Mattéo Rossillol‑‑Laruelle <beatussum@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "core/IniDom/Section.hpp"

namespace yetam::core::IniDom
{
    bool operator<(const Section& a, const std::string_view b) noexcept
    {
        return a.m_name_ < b;
    }

    bool operator>(const Section& a, const std::string_view b) noexcept
    {
        return a.m_name_ > b;
    }

    bool operator<(const std::string_view a, const Section& b) noexcept
    {
        return a < b.m_name_;
    }

    bool operator>(const std::string_view a, const Section& b) noexcept
    {
        return a > b.m_name_;
    }

    std::string Section::to_string(const std::string& __path) const
    {
        std::string ret;

        if (has_parameters()) {
            ret += '[' + __path + "]\n";

            for (const auto& i : m_parameters_)
                ret += static_cast<std::string>(i);

            if (has_subsections())
                ret += '\n';
        }

        for (const auto& i : m_subsections_) {
            if (i.is_empty())
                continue;

            ret += i.to_string(__path + '/' + i.m_name_);
        }

        return ret;
    }

    Section::Section(std::string __name)
        : m_name_(std::move(__name))
        , m_parameters_()
        , m_subsections_()
    {
        if (m_name_.find('/') != std::string::npos) {
            throw std::invalid_argument( "The section name (\"" + m_name_
                                       + "\") cannot contain "
                                         "slash (\"/\").");
        }
    }

    bool Section::is_empty() const
    {
        return !has_subsections() && !has_parameters();
    }

    bool Section::operator<(const Section& b) const noexcept
    {
        return m_name_ < b.m_name_;
    }

    bool Section::operator>(const Section& b) const noexcept
    {
        return m_name_ > b.m_name_;
    }

    Section& Section::operator<<(Section __s)
    {
        m_subsections_.insert(__s);

        return *this;
    }

    Section& Section::operator<<(Parameter __p)
    {
        m_parameters_.insert(__p);

        return *this;
    }

    /*
     * In the following two methods, one allows oneself to `const_cast` because
     * the implementation of equality and comparison are based on a constant
     * member: e.g., even if the content of a subsection was changed, its name
     * would not be.
     */

    Section& Section::subsection(const std::string_view __name)
    {
        const auto match = __name.find('/');

        if (match == std::string_view::npos) {
            return const_cast<Section&>(*m_subsections_.find(__name));
        } else {
            return const_cast<Section&>(*m_subsections_.find(__name.substr(0, match)))
                   .subsection(__name.substr(match + 1));
        }
    }

    Parameter& Section::parameter(const std::string_view __name)
    {
        return const_cast<Parameter&>(*m_parameters_.find(__name));
    }
}
