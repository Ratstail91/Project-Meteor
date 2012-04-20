/* File Name: point.h
 * Author: Kayne Ruse
 * Date: 21/4/2012
 * Copyright: (c) Kayne Ruse 2012
 * 
 * This file is part of Project RPG.
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

#include "SDL_opengl.h"

class Point {
public:
	/* Public access members */
	Point();
	Point(GLfloat, GLfloat, GLfloat);

	GLfloat& operator[](int);

	GLfloat* GetVertices();

	/* Accessors and mutators */
	void SetPosition(GLfloat, GLfloat, GLfloat);
	void ShiftPosition(GLfloat, GLfloat, GLfloat);

	GLfloat SetX(GLfloat);
	GLfloat SetY(GLfloat);
	GLfloat SetZ(GLfloat);

	GLfloat ShiftX(GLfloat);
	GLfloat ShiftY(GLfloat);
	GLfloat ShiftZ(GLfloat);

	GLfloat GetX();
	GLfloat GetY();
	GLfloat GetZ();

private:
	/* Private access members */
	GLfloat m_fVertices[3]; //x, y, z
};

#endif
