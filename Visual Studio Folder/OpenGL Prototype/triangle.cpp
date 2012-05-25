/* File Name: triangle.cpp
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
#include "triangle.h"

//-------------------------
//Public access members
//-------------------------

Triangle::Triangle() {
	//
}

Triangle::Triangle(Point a, Point b, Point c) {
	v1 = a;
	v2 = b;
	v3 = c;
}

Point& Triangle::operator[](int i) {
	switch(i) {
		case 0: return v1;
		case 1: return v2;
		case 2: return v3;
		default: throw(std::out_of_range("Unknown Triangle element"));
	}
}
