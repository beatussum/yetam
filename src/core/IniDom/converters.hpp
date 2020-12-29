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


#ifndef YETAM_CORE_INIDOM_CONVERTERS_HPP
#define YETAM_CORE_INIDOM_CONVERTERS_HPP

#include "../type_traits.hpp"

namespace IniDom
{
    template <class _T, typename _enabled = std::true_type>
    struct converter final {};

    template <class _T>
    struct converter<_T, is_cstring_like_t<_T>> final
    {
        static std::string convert(const _T __v)
        {
            return static_cast<std::string>(__v);
        }

        static _T deconvert(const std::string_view __s)
        {
            return __s.data();
        }
    };

    template <>
    struct converter<bool> final
    {
        static std::string convert(const bool __v)
        {
            return __v ? "true" : "false";
        }

        static bool deconvert(const std::string_view __s)
        {
            return __s == "true";
        }
    };

    template <>
    struct converter<char> final
    {
        static std::string convert(const char __v)
        {
            return std::string(1, __v);
        }

        static char deconvert(const std::string_view __s)
        {
            return __s.front();
        }
    };

    template <>
    struct converter<std::string> final
    {
        static std::string convert(const std::string __v)
        {
            return __v;
        }

        static std::string deconvert(const std::string __s)
        {
            return __s;
        }
    };
};

#endif // YETAM_CORE_INIDOM_CONVERTERS_HPP
