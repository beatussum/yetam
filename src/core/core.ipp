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


namespace yetam::core
{
    template <class _Number>
    _Number str_to_number(const std::string& __s)
    {
        if (std::is_floating_point_v<_Number>) {
            return static_cast<_Number>(strtold(__s.data(), nullptr));
        } else if (std::is_signed_v<_Number>) {
            return static_cast<_Number>(strtoll(__s.data(), nullptr, 10));
        } else {
            return static_cast<_Number>(strtoull(__s.data(), nullptr, 10));
        }
    }
}
