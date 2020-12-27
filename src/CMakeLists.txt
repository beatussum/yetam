# Copyright (C) 2020 Mattéo Rossillol‑‑Laruelle <beatussum@protonmail.com>
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU General Public License as published by the Free Software
# Foundation, either version 3 of the License, or (at your option) any later
# version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
# details.
#
# You should have received a copy of the GNU General Public License along with
# this program. If not, see <https://www.gnu.org/licenses/>.


set(YETAM_HPP
    core/IniDom/Parameter.hpp
    core/IniDom/Section.hpp)
set(YETAM_IPP
    core/IniDom/Section.ipp)
set(YETAM_CPP
    core/IniDom/Parameter.cpp
    core/IniDom/Section.cpp
    main.cpp)

add_executable(yetam "${YETAM_HPP}" "${YETAM_IPP}" "${YETAM_CPP}")

add_to_doc("${YETAM_HPP}")
