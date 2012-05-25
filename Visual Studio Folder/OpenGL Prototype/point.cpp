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
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(GLfloat a, GLfloat b, GLfloat c) {
	x = a;
	y = b;
	z = c;
}

GLfloat& Point::operator[](int i) {
	switch(i) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		default: throw(std::out_of_range("Unknown Point element"));
	}
}
