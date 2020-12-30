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


#include "Section.hpp"

#include <algorithm>

namespace IniDom
{
    void Section::check_name(const std::string_view __n) const
    {
        if (__n.find('/') != std::string::npos) {
            throw std::invalid_argument("The section name cannot contain "
                                        "slash (\"/\").");
        }
    }

    Section::Section(std::string __name)
        : m_name_(std::move(__name))
        , m_subsections_()
        , m_parameters_()
    {
        check_name(m_name_);
    }

    bool Section::is_empty() const
    {
        return !has_subsections() && !has_parameters();
    }

    Section::operator std::string() const
    {
        std::string ret;

        if (has_parameters()) {
            ret += '[' + m_name_ + "]\n";

            for (const auto& i : m_parameters_)
                ret += static_cast<std::string>(i);
        }

        for (const auto& i : m_subsections_) {
            if (i.is_empty())
                continue;

            ret += static_cast<std::string>(i);
        }

        return ret;
    }

    Section& Section::operator<<(Section __s)
    {
        __s.m_name_ = m_name_ + '/' + __s.m_name_;

        m_subsections_.push_back(std::move(__s));

        return *this;
    }

    Section& Section::operator<<(Parameter __p)
    {
        m_parameters_.push_back(std::move(__p));

        return *this;
    }

    Section& Section::find_subsection(const std::string& __name)
    {
        check_name(__name);

        return *std::find_if(m_subsections_.begin(), m_subsections_.end(),
            [&](const Section& __r) {
                if (__r.m_name_.size() < ( __name.size() + 1 ))
                    return false;

                return __r.m_name_.compare( __r.m_name_.size() - ( __name.size() + 1 )
                                          , std::string::npos, '/' + __name) == 0;
            }
        );
    }

    Parameter& Section::find_parameter(const std::string_view __name)
    {
        return *std::find_if(m_parameters_.begin(), m_parameters_.end(),
            [&](const Parameter& __r) { return __r.m_name_ == __name; }
        );
    }
}
