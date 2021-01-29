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


#include "core/IniDom/core.hpp"

namespace yetam::core::IniDom
{
    template <class _T>
    Parameter::Parameter(std::string __name, _T&& __value)
        : m_name_(std::move(__name))
        , m_value_(converter<remove_cvref_t<_T>>
                   ::convert(std::forward<_T>(__value)))
    {
        if (  contains_any_of(m_name_, forbidden_characters)
           || contains_any_of(m_value_, forbidden_characters))
        {
            throw std::invalid_argument( "The parameter (\""
                                       + static_cast<std::string>(*this)
                                       + "\") cannot contain a forbidden "
                                         "character.");
        }
    }
}
