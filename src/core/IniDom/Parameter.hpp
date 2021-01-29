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


#ifndef YETAM_INIDOM_PARAMETER_HPP
#define YETAM_INIDOM_PARAMETER_HPP

#include "core/IniDom/converters.hpp"

namespace yetam::core::IniDom
{
    class Parameter
    {
        friend class Section;
        friend bool operator<(const Parameter&, const std::string_view) noexcept;
        friend bool operator>(const Parameter&, const std::string_view) noexcept;
        friend bool operator<(const std::string_view, const Parameter&) noexcept;
        friend bool operator>(const std::string_view, const Parameter&) noexcept;
    public:
        template <class _T>
        Parameter(std::string __name, _T&& __value);
    public:
        std::string get_name() const { return m_name_; }
    public:
        explicit operator std::string() const;

        bool operator<(const Parameter&) const noexcept;
        bool operator>(const Parameter&) const noexcept;

        template <class _T>
        auto as() const { return converter<_T>::deconvert(m_value_); }
    private:
        const std::string m_name_;
        std::string m_value_;
    };
}

#include "core/IniDom/Parameter.ipp"
#endif // YETAM_INIDOM_PARAMETER_HPP
