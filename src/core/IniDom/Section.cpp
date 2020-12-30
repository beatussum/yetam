/*
 * Copyright (C) 2020 Mattéo Rossillol‑‑Laruelle <beatussum@protonmail.com>
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

namespace IniDom
{
    void Section::check_name(const std::string_view __n) const
    {
        if (__n.find('/') != std::string::npos) {
            throw std::invalid_argument("The section name cannot contain "
                                        "slash (\"/\").");
        }
    }

    std::string Section::toString(const std::string& __fullname) const
    {
        std::string ret;

        if (has_parameters()) {
            ret += '[' + __fullname + "]\n";

            for (const auto& i : m_parameters_)
                ret += static_cast<std::string>(i);

            if (has_subsections())
                ret += '\n';
        }

        for (const auto& i : m_subsections_) {
            if (i.is_empty())
                continue;

            ret += i.toString(__fullname + '/' + i.m_name_);
        }

        return ret;
    }

    Section::Section(std::string __name)
        : m_name_(std::move(__name))
        , m_parameters_()
        , m_subsections_()
    {
        check_name(m_name_);
    }

    bool Section::is_empty() const
    {
        return !has_subsections() && !has_parameters();
    }

    Section& Section::operator<<(Section __s)
    {
        m_subsections_.push_back(std::move(__s));

        return *this;
    }

    Section& Section::operator<<(Parameter __p)
    {
        m_parameters_.push_back(std::move(__p));

        return *this;
    }

    Section& Section::find_subsection(const std::string_view __name)
    {
        return find_by_name(m_subsections_, __name);
    }

    Parameter& Section::find_parameter(const std::string_view __name)
    {
        return find_by_name(m_parameters_, __name);
    }
}
