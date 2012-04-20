/* File Name: plane.h
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
 *     A triangular plane in 3D space.
*/
#ifndef KR_PLANE_H_
#define KR_PLANE_H_

#include "point.h"

class Plane {
public:
	/* Public access members */
	Plane();
	Plane(Point, Point, Point);
	Point& operator[](int);

	void Render();

private:
	/* Private access members */
	Point m_vertices[3];
};

#endif
