/* File Name: point.h
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
#ifndef KR_POINT_H_
#define KR_POINT_H_

#include "global_macros.h"
#include "SDL_opengl.h"

class Point {
public:
	/* Public access members */
	Point();
	Point(GLfloat, GLfloat, GLfloat);

	GLfloat& operator[](int);

	/* Accessors and mutators */
	BP_MEMBER(GetX, SetX, GLfloat, x);
	BP_MEMBER(GetY, SetY, GLfloat, y);
	BP_MEMBER(GetZ, SetZ, GLfloat, z);
};

#endif
