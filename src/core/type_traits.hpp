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

template <class _T>
struct remove_cvref
{
    using type = std::remove_cv_t<std::remove_reference_t<_T>>;
};

template <class _T>
using remove_cvref_t = typename remove_cvref<_T>::type;


template <class _T>
struct is_cstring_like
    : public std::bool_constant<
          std::is_convertible_v<_T, std::string> &&
          std::is_convertible_v<
              decltype(std::string().data()),
              _T
          >
      >
{
    using convertible_type = _T;
};

template <class _T, size_t _s>
struct is_cstring_like<_T[_s]>
    : public is_cstring_like<const _T*>
{};

template <class _T, size_t _s>
struct is_cstring_like<_T (&)[_s]>
    : public is_cstring_like<const _T*>
{};

template <class _T>
using is_cstring_like_t = typename is_cstring_like<_T>::type;

#endif // YETAM_CORE_TYPE_TRAITS_HPP
