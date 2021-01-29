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


#ifndef YETAM_INIDOM_SECTION_HPP
#define YETAM_INIDOM_SECTION_HPP

#include "core/IniDom/Parameter.hpp"

#include <set>

namespace IniDom
{
    class Section
    {
        friend bool operator<(const Section&, const std::string_view) noexcept;
        friend bool operator>(const Section&, const std::string_view) noexcept;
        friend bool operator<(const std::string_view, const Section&) noexcept;
        friend bool operator>(const std::string_view, const Section&) noexcept;
    private:
        using parameters_t = std::set<Parameter, std::less<>>;
        using subsections_t = std::set<Section, std::less<>>;
    private:
        std::string to_string(const std::string& __path) const;
    public:
        explicit Section(std::string __name);
    public:
        std::string get_name() const { return m_name_; }

        bool is_empty() const;
        bool has_parameters() const { return !m_parameters_.empty(); }
        bool has_subsections() const { return !m_subsections_.empty(); }
    public:
        explicit operator std::string() const { return to_string(m_name_); }

        bool operator<(const Section&) const noexcept;
        bool operator>(const Section&) const noexcept;

        Section& operator<<(Parameter);
        Section& operator<<(Section);

        Parameter& parameter(const std::string_view __name);
        Section& subsection(const std::string_view __name);
    private:
        const std::string m_name_;
        parameters_t m_parameters_;
        subsections_t m_subsections_;
    };
}

#endif // YETAM_INIDOM_SECTION_HPP
