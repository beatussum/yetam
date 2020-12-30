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

#include "Parameter.hpp"

#include <list>

namespace IniDom
{
    class Section
    {
    private:
        using subsections_t = std::list<Section>;
        using parameters_t = std::list<Parameter>;
    private:
        void check_name(const std::string_view) const;

        template <class _Container>
        typename _Container::reference find_by_name( _Container&
                                                   , const std::string_view);

        std::string toString(const std::string& __fullname) const;
    public:
        Section() noexcept = default;
        explicit Section(std::string __name);
    public:
        std::string get_name() const { return m_name_; }
    public:
        explicit operator std::string() const { return toString(m_name_); }

        bool is_empty() const;
        bool has_subsections() const { return !m_subsections_.empty(); }
        bool has_parameters() const { return !m_parameters_.empty(); }

        Section& operator<<(Section);
        Section& operator<<(Parameter);

        Section& find_subsection(const std::string_view __name);
        Parameter& find_parameter(const std::string_view __name);
    private:
        const std::string m_name_;
        subsections_t m_subsections_;
        parameters_t m_parameters_;
    };
}

#include "Section.ipp"
#endif // YETAM_INIDOM_SECTION_HPP
