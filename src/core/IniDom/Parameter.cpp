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


#include "core/IniDom/Parameter.hpp"

namespace IniDom
{
    bool operator<(const Parameter& a, const std::string_view b) noexcept
    {
        return a.m_name_ < b;
    }

    bool operator>(const Parameter& a, const std::string_view b) noexcept
    {
        return a.m_name_ > b;
    }

    bool operator<(const std::string_view a, const Parameter& b) noexcept
    {
        return a < b.m_name_;
    }

    bool operator>(const std::string_view a, const Parameter& b) noexcept
    {
        return a > b.m_name_;
    }

    bool Parameter::operator<(const Parameter& b) const noexcept
    {
        return m_name_ < b.m_name_;
    }

    bool Parameter::operator>(const Parameter& b) const noexcept
    {
        return m_name_ > b.m_name_;
    }

    Parameter::operator std::string() const
    {
        return m_name_ + '=' + m_value_ + '\n';
    }
}
