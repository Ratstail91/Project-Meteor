/* File Name: point.cpp
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
 *     A single point in three dimensional space.
*/
#include <stdexcept>
#include "point.h"

//-------------------------
//Public access members
//-------------------------

Point::Point() {
	m_fCoords[0] = 0;
	m_fCoords[1] = 0;
	m_fCoords[2] = 0;
}

Point::Point(GLfloat a, GLfloat b, GLfloat c) {
	m_fCoords[0] = a;
	m_fCoords[1] = b;
	m_fCoords[2] = c;
}

GLfloat& Point::operator[](int i) {
	if (i < 0 || i >= 3) {
		throw(std::out_of_range("Unknown Point element"));
	}

	return m_fCoords[i];
}

GLfloat* Point::GetCoords() {
	return m_fCoords;
}

//-------------------------
//Accessors and mutators
//-------------------------

void Point::SetPosition(GLfloat a, GLfloat b, GLfloat c) {
	m_fCoords[0] = a;
	m_fCoords[1] = b;
	m_fCoords[2] = c;
}

void Point::ShiftPosition(GLfloat a, GLfloat b, GLfloat c) {
	m_fCoords[0] += a;
	m_fCoords[1] += b;
	m_fCoords[2] += c;
}

GLfloat Point::SetX(GLfloat f) {
	return m_fCoords[0] = f;
}

GLfloat Point::SetY(GLfloat f) {
	return m_fCoords[1] = f;
}

GLfloat Point::SetZ(GLfloat f) {
	return m_fCoords[2] = f;
}

GLfloat Point::ShiftX(GLfloat f) {
	return m_fCoords[0] += f;
}

GLfloat Point::ShiftY(GLfloat f) {
	return m_fCoords[1] += f;
}

GLfloat Point::ShiftZ(GLfloat f) {
	return m_fCoords[2] += f;
}

GLfloat Point::GetX() {
	return m_fCoords[0];
}

GLfloat Point::GetY() {
	return m_fCoords[1];
}

GLfloat Point::GetZ() {
	return m_fCoords[2];
}
