/* File Name: triangle.h
 * Author: Kayne Ruse
 * Date: 21/4/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Project Meteor.
 * 
 * Project Meteor is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * Project Meteor is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with Project Meteor.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * Description: 
 *     A triangular plane in 3D space.
*/
#ifndef KR_TRIANGLE_H_
#define KR_TRIANGLE_H_

#include "global_macros.h" //BAD KAYNE!! I should rename this in codebase, or even, I don't know, remove it?
#include "point.h"

class Triangle {
public:
	/* Public access members */
	Triangle();
	Triangle(Point, Point, Point);
	Point& operator[](int);

	BP_MEMBER(GetV1, SetV1, Point, v1);
	BP_MEMBER(GetV2, SetV2, Point, v2);
	BP_MEMBER(GetV3, SetV3, Point, v3);
};

#endif
