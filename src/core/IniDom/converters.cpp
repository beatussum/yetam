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


#include "converters.hpp"

namespace IniDom
{
    std::string converter<bool>::convert(const bool __v)
    {
        return __v ? "true" : "false";
    }

    bool converter<bool>::deconvert(const std::string_view __s)
    {
        return __s == "true";
    }

    std::string converter<char>::convert(const char __v)
    {
        return std::string(1, __v);
    }

    char converter<char>::deconvert(const std::string_view __s)
    {
        return __s.front();
    }

    std::string converter<std::string>::convert(const std::string __v)
    {
        return __v;
    }

    std::string converter<std::string>::deconvert(const std::string_view __s)
    {
        return static_cast<std::string>(__s);
    }
}
