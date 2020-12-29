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


#ifndef YETAM_CORE_TYPE_TRAITS_HPP
#define YETAM_CORE_TYPE_TRAITS_HPP

#include <string>

template <class _T, typename _enabled = std::true_type>
struct is_cstring_like : public std::false_type {};

template <class _T>
struct is_cstring_like<
    _T,
    typename std::is_convertible<
        decltype(std::string().data()),
        _T
    >::type>
    : public std::true_type
{};

template <class _T>
struct is_cstring_like<
    _T,
    typename std::is_convertible<
        decltype(std::string().data()),
        decltype(std::begin(std::declval<_T>()))
    >::type>
    : public std::true_type
{};

template <class _T>
using is_cstring_like_t = typename is_cstring_like<_T>::type;

#endif // YETAM_CORE_TYPE_TRAITS_HPP
