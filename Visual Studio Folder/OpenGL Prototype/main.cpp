/* File Name: main.cpp
 * Author: Kayne Ruse
 * Date: 20/4/2012
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
 *     ...
*/
#include <iostream>
#include "SDL.h"
#include "SDL_opengl.h"
#include "simple_callbacks.h"
using namespace std;

/* This triangle class and the point class will probably be useless overall.
*/
#include "triangle.h"

//-------------------------
//preprocessor directives
//-------------------------

#define CASE break; case

//-------------------------
//Declarations
//-------------------------

//global variables
SDL_Surface* g_pScreen = NULL;
GLfloat g_fSpin = 0;
bool g_bRotate = true;

Triangle triangle;

//main loop
void Init();
void Update();
void Render();

//event loop
void QuitEvent			(SDL_Event const* const);
void MouseMotion		(SDL_Event const* const);
void MouseButtonDown	(SDL_Event const* const);
void MouseButtonUp		(SDL_Event const* const);
void KeyDown			(SDL_Event const* const);
void KeyUp				(SDL_Event const* const);

//utilities
void SetScreen			(int w, int h);

//-------------------------
//Mainline
//-------------------------

int SDL_main(int, char**) {
	scSetInitCallback(Init);
	scSetQuitCallback(SDL_Quit);
	scSetUpdateCallback(Update);
	scSetRenderCallback(Render);

	scSetEventCallback(QuitEvent,		SDL_QUIT);
	scSetEventCallback(MouseMotion,		SDL_MOUSEMOTION);
	scSetEventCallback(MouseButtonDown,	SDL_MOUSEBUTTONDOWN);
	scSetEventCallback(MouseButtonUp,	SDL_MOUSEBUTTONUP);
	scSetEventCallback(KeyDown,			SDL_KEYDOWN);
	scSetEventCallback(KeyUp,			SDL_KEYUP);

	scProc();

	return 0;
}

//-------------------------
//Definitions
//-------------------------

//main loop
void Init() {
	//init SDL
	if ( SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Failed to initialize SDL" << endl;
		exit(1);
	}

	//SDL_GL_SetAttribute is called before SDL_SetVideoMode

	SetScreen(600, 600);

	//Setup OpenGL
	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0);

	glShadeModel(GL_SMOOTH);

	//culling
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	//arrays
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
//	textures, etc.

	//debugging
	triangle[0][0] = 0.0f;
	triangle[0][1] = 0.0f;
	triangle[0][2] = 0.0f;

	triangle[1][0] = 0.5f;
	triangle[1][1] = 0.0f;
	triangle[1][2] = 0.0f;

	triangle[2][0] = 0.5f;
	triangle[2][1] = 0.5f;
	triangle[2][2] = 0.0f;
}

void Update() {
	if (g_bRotate) {
		g_fSpin += 0.2f;

		if (g_fSpin > 360) g_fSpin = 0;
	}
}

void Render() {
	//clear the pixels
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	//begin rotation
	glPushMatrix();
	glRotatef(g_fSpin, 0, 0, 1);

	//draw the white polygon
	glColor3f( 1, 1, 1);
	glRectf(-0.25f, -0.25f, 0.25f, 0.25f);

	//end rotation
	glPopMatrix();

/*	//draw the green arrow
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
		glVertex2f(0.4f, 0.0f);
		glVertex2f(0.6f, 0.15f);
		glVertex2f(0.4f, 0.3f);
		glVertex2f(0.0f, 0.3f);
		glVertex2f(0.0f, 0.0f);
	glEnd();

	//draw the red triangle
	glColor3f(1, 0, 0);

	glBegin(GL_TRIANGLES);
		glVertex3fv(reinterpret_cast<GLfloat*>(&triangle[0]));
		glVertex3fv(reinterpret_cast<GLfloat*>(&triangle[1]));
		glVertex3fv(reinterpret_cast<GLfloat*>(&triangle[2]));
	glEnd();
*/
	//draw the arrays
	static GLfloat afVertices[] = {
		0.0, 0.0,
		0.5, 0.0,
		0.75, 0.5,
		0.75, -0.5
	};

	static GLfloat afColours[] = {
		1.0,	0.0,	0.0,
		0.0,	1.0,	0.0,
		0.0,	0.0,	1.0,
		1.0,	1.0,	0.0
	};

	//dn't forget culling when writing this order: CCW
	static GLubyte aiFaces[] = {
		0, 1, 2, 0, 3, 1, 2, 1, 3
	};

	glColorPointer(3, GL_FLOAT, 0, afColours);
	glVertexPointer(2, GL_FLOAT, 0, afVertices);

//	glBegin(GL_TRIANGLES);
//		glArrayElement(0);
//		glArrayElement(1);
//		glArrayElement(2);
//	glEnd();

	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_BYTE, aiFaces); //hops around the arrays
//	glDrawArrays(GL_TRIANGLES, 0, 3); //plows through the arrays

	/* Overall I think that interleaved verticies would be the best approach given
	 * The requirements of this game. I will need to research texturing of couse, but
	 * That is just a matter of time.
	*/

	//start processing the buffered OpenGL routines
	glFlush();

	//SDL manages the actual screen
	SDL_GL_SwapBuffers();
}

//event loop
void QuitEvent(SDL_Event const* const event) {
	scQuit();
}

void MouseMotion(SDL_Event const* const event) {
	//
}

void MouseButtonDown(SDL_Event const* const event) {
	if (g_bRotate)
		g_bRotate = false;
	else
		g_bRotate = true;
}

void MouseButtonUp(SDL_Event const* const event) {
	//
}

void KeyDown(SDL_Event const* const event) {
	switch(event->key.keysym.sym) {
		case SDLK_ESCAPE:
			QuitEvent(NULL);
			break;
	}
}

void KeyUp(SDL_Event const* const event) {
	//
}

//utilities
void SetScreen(int w, int h) {
	//init the screen, w/ OpenGL flags
	g_pScreen = SDL_SetVideoMode(w, h, SDL_GetVideoInfo()->vfmt->BitsPerPixel, SDL_HWSURFACE|SDL_GL_DOUBLEBUFFER|SDL_OPENGL);

	if (g_pScreen == NULL) {
		cerr << "Failed to initialize the screen" << endl;
		exit(1);
	}

	//initialise the OpenGL viewing values
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1); //derped numbers center around (0,0,0); this should have the adjustment-according-to-the-screen-size code as an argument
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
