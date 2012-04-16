/* File Name: mesh.h
 * Author: Kayne Ruse
 * Date: 16/4/2012
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
 *     This is a basic class for handling the ingame models.
*/
#ifndef KR_MESH_H_
#define KR_MESH_H_ 20120416

#include "SDL_opengl.h"
#include "llist.h"

class Mesh {
public:
	/* Internal class definitions */
	class Point {
	public:
		/* Public access members */
		Point();
		Point(GLfloat, GLfloat, GLfloat);
		GLfloat& operator[](int);

		GLfloat* GetVerts();

	private:
		/* Private access members */
		GLfloat m_fArray[3];
	};

	class Triangle {
	public:
		/* Public access members */
		Triangle();
		Triangle(Point, Point, Point);
		Point& operator[](int);

	private:
		/* Private access members */
		Point m_array[3];
	};

	/* Public access members */
	Mesh();
	~Mesh();

	void Load(const char* szFileName);
	void Save(const char* szFileName);
	void Clear();

	LList<Triangle>* GetFaceList();

	void Render();

private:
	/* Private access members */
	LList<Triangle> m_LLFaces;
};

#endif
