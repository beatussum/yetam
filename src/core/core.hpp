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


#ifndef YETAM_CORE_CORE_HPP
#define YETAM_CORE_CORE_HPP

#include <string>

namespace yetam::core
{
    template <class _Number>
    _Number str_to_number(const std::string&);

    std::string to_string(const std::byte);
}

#include "core/core.ipp"
#endif // YETAM_CORE_CORE_HPP
