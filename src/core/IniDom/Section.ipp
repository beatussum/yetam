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


#include <algorithm>

namespace IniDom
{
    template <class _Container>
    typename _Container::reference Section::find_by_name( _Container& __c
                                                        , const std::string_view __name)
    {
        return *std::find_if(__c.begin(), __c.end(),
            [&](typename _Container::const_reference __r) { return __r.m_name_ == __name; }
        );
    }
}
