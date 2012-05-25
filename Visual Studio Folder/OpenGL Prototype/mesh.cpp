/* File Name: mesh.cpp
 * Author: Kayne Ruse
 * Date: 16/4/2012
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
 *     This is a basic class for handling the ingame models.
*/
#include <stdexcept>
#include "mesh.h"

//-------------------------
//Internal class Point
//-------------------------

//-------------------------
//Public access members
//-------------------------

Mesh::Point::Point() {
	m_fArray[0] = 0;
	m_fArray[1] = 0;
	m_fArray[2] = 0;
}

Mesh::Point::Point(GLfloat a, GLfloat b, GLfloat c) {
	m_fArray[0] = a;
	m_fArray[1] = b;
	m_fArray[2] = c;
}

GLfloat& Mesh::Point::operator[](int i) {
	if (i < 0 || i >= 3) {
		throw(std::out_of_range("Unknown Mesh::Point element"));
	}

	return m_fArray[i];
}

GLfloat* Mesh::Point::GetVerts() {
	return m_fArray;
}

//-------------------------
//Internal class Triangle
//-------------------------

//-------------------------
//Public access members
//-------------------------

Mesh::Triangle::Triangle() {
	//Empty
}

Mesh::Triangle::Triangle(Point a, Point b, Point c) {
	m_array[0] = a;
	m_array[1] = b;
	m_array[2] = c;
}

Mesh::Point& Mesh::Triangle::operator[](int i) {
	if (i < 0 || i >= 3) {
		throw(std::out_of_range("Unknown Mesh::Triangle element"));
	}

	return m_array[i];
}

//-------------------------
//Class Mesh
//-------------------------

//-------------------------
//Public access members
//-------------------------

Mesh::Mesh() {
	//
}

Mesh::~Mesh() {
	//
}

void Mesh::Load(const char* szFileName) {
	//
}

void Mesh::Save(const char* szFileName) {
	//
}

void Mesh::Clear() {
	while(m_LLFaces.Head() != NULL) {
		delete m_LLFaces.Pop();
	}
}

LList<Mesh::Triangle>* Mesh::GetFaceList() {
	return &m_LLFaces;
}

void Mesh::Render() {
	glBegin(GL_TRIANGLES);

	for (LList<Triangle>::iterator it = m_LLFaces.Head(); it != NULL; it = it->m_pNext) {
		//for each face
		for (int i = 0; i < 3; i++) {
			//for each point
			glVertex3fv( (*it->m_pData)[i].GetVerts() );
		}
	}

	glEnd();
}