/* File Name: plane.cpp
 * Author: Kayne Ruse
 * Date: 21/4/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Project Meteor.
 * 
 * Project RPG is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Project RPG is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Project RPG.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     A triangular plane in 3D space.
*/
#include <stdexcept>
#include "plane.h"

//-------------------------
//Public access members
//-------------------------

Plane::Plane() {
	//
}

Plane::Plane(Point a, Point b, Point c) {
	m_vertices[0] = a;
	m_vertices[1] = b;
	m_vertices[2] = c;
}

Point& Plane::operator[](int i) {
	if (i < 0 || i >= 3) {
		throw(std::out_of_range("Unknown Plane element"));
	}

	return m_vertices[i];
}

void Plane::Render() {
	glVertex3fv(m_vertices[0].GetCoords());
	glVertex3fv(m_vertices[1].GetCoords());
	glVertex3fv(m_vertices[2].GetCoords());
}