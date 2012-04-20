/* File Name: main.cpp
 * Author: Kayne Ruse
 * Date: 20/4/2012
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
 *     Basic bulky camera controls.
*/
#include <iostream>
#include "SDL.h"
#include "SDL_opengl.h"
#include "xFramework.h"
using namespace std;

#include "point.h"
Point camera;

//-------------------------
//preprocessor directives
//-------------------------

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP (SDL_GetVideoInfo()->vfmt->BitsPerPixel)
#define SCREEN_FLAGS (SDL_HWSURFACE|SDL_OPENGL)

#define SCALE(x) x

#define CASE break; case

//-------------------------
//Declarations
//-------------------------

//xFramework
void Init();
void Update();
void Render();

//event loop
void Quit				(SDL_Event const* const) { xQuit(); };
void MouseMotion		(SDL_Event const* const);
void MouseButtonDown	(SDL_Event const* const);
void MouseButtonUp		(SDL_Event const* const);
void KeyDown			(SDL_Event const* const);
void KeyUp				(SDL_Event const* const);

//utilities(temps)
void DrawPoint(GLfloat* vert, GLubyte* col) {
	glColor4ubv(col);
	glVertex3fv(vert);
}

//-------------------------
//Mainline
//-------------------------

int SDL_main(int, char**) {
	xSetInitCallback(Init);
	xSetQuitCallback(SDL_Quit);
	xSetUpdateCallback(Update);
	xSetRenderCallback(Render);

	xSetEventCallback(Quit,				SDL_QUIT);
	xSetEventCallback(MouseMotion,		SDL_MOUSEMOTION);
	xSetEventCallback(MouseButtonDown,	SDL_MOUSEBUTTONDOWN);
	xSetEventCallback(MouseButtonUp,	SDL_MOUSEBUTTONUP);
	xSetEventCallback(KeyDown,			SDL_KEYDOWN);
	xSetEventCallback(KeyUp,			SDL_KEYUP);

	xProc();

	return 0;
}

//-------------------------
//Definitions
//-------------------------

void Init() {
	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "Failed to init SDL video" << endl;
	}

	//set OpenGL attributes
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//set video mode
	if (SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SCREEN_FLAGS) == NULL) {
		cerr << "Failed to set video mode" << endl;
	}

	//shading model
	glShadeModel(GL_SMOOTH);

	//culling
	glCullFace(GL_BACK);
	glFrontFace(GL_CW); //CLOCKWISE 
	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	//viewport
	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	//matrix
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();

	//perspective
	gluPerspective(60.0, (double)(SCREEN_WIDTH)/(double)(SCREEN_HEIGHT), 1.0, 1024.0);
//	gluLookAt(0,-2, 2, 0, 0, -1, 0, 1, 0);
}

void Update() {
	//debug
	cout << camera.GetX() << "\t" << camera.GetY() << "\t" << camera.GetZ() << endl;
}

void Render() {
	//prep OpenGL
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//draw my stuff
	gluLookAt(
		camera.GetX(), camera.GetY(), camera.GetZ(),
		0, 0, 0,
		camera.GetX(), camera.GetY()+1, camera.GetZ()
		);

	//colours
	static GLubyte white[]	= {255, 255, 255, 255};
	static GLubyte black[]	= {0, 0, 0, 255};
	static GLubyte red[]	= {255, 0, 0, 255};
	static GLubyte yellow[]	= {255, 255, 0, 255};
	static GLubyte blue[]	= {0, 0, 255, 255};
	static GLubyte green[]	= {0, 255, 0, 255};

	//vertices
	static GLfloat v1[] = {-1.0f,  1.0f, 0.0f}; //top-corner
	static GLfloat v2[] = {-1.0f,  0.0f, 0.0f}; //right-corner
	static GLfloat v3[] = {-1.0f,  0.0f,-1.0f}; //short-corner, into the screen
	static GLfloat v4[] = { 1.0f,  0.0f, 0.0f}; //point-corner

	//translation
//	glTranslatef(0, -.5, -3);

	//rotation
	static float angle = 0.0f;
//	glRotatef(angle, 0.0, 1.0, 0.0 ); //comment this out to disable the rotation

	if( (angle+=.1f) > 360.0f ) {
		angle = 0.0f;
	}

	//begin the shape
	glBegin(GL_TRIANGLES);

	//side 1
	DrawPoint(v1, green);
	DrawPoint(v2, red);
	DrawPoint(v3, yellow);

	//side 2
	DrawPoint(v1, green);
	DrawPoint(v4, blue);
	DrawPoint(v2, red);

	//side 3
	DrawPoint(v1, green);
	DrawPoint(v3, yellow);
	DrawPoint(v4, blue);

	//base
	DrawPoint(v2, red);
	DrawPoint(v4, blue);
	DrawPoint(v3, yellow);

	glEnd();

	//swap the buffers
	SDL_GL_SwapBuffers();
}

void MouseMotion(SDL_Event const* const event) {
	//
}

void MouseButtonDown(SDL_Event const* const event) {
	//
}

void MouseButtonUp(SDL_Event const* const event) {
	//
}

void KeyDown(SDL_Event const* const event) {
	switch(event->key.keysym.sym) {
		case SDLK_ESCAPE:
			xQuit();
			break;

		//camera control
		CASE SDLK_w: camera.ShiftZ(-1);
		CASE SDLK_s: camera.ShiftZ( 1);
		CASE SDLK_a: camera.ShiftX(-1);
		CASE SDLK_d: camera.ShiftX( 1);
		CASE SDLK_q: camera.ShiftY( 1);
		CASE SDLK_z: camera.ShiftY(-1);

		CASE SDLK_SPACE: camera.SetPosition(0, 0, 0);
	}
}

void KeyUp(SDL_Event const* const event) {
	//
}
