/* File Name: main.cpp
 * Copyright: (c) Kayne Ruse, all rights reserved.
 * Author: Kayne Ruse
 * Date: 
 * Description: 
 * This is my testbed for learning OpenGL, also using SDL.
 * So far, I have a rotating triangle, without culling.
 * No control for the speed of the triangle, FPSUtility isn't here yet.
*/
#include <iostream>
#include "SDL.h"
#include "SDL_opengl.h"
using namespace std;

//-------------------------
//Preprocessor directives
//-------------------------

#define WIDTH 640
#define HEIGHT 480
#define BPP 32
#define FLAGS (SDL_HWSURFACE|SDL_OPENGL)

//-------------------------
//Function declarations
//-------------------------

void InitSDL();
void InitOpenGL();
void InitOpenGLAttributes();
void DrawShape();
void DrawPoint(GLfloat* vert, GLubyte* col);

//-------------------------
//Mainline
//-------------------------

int SDL_main(int, char**) {
	InitSDL();
	InitOpenGL();

	bool bRunning = true;
	while(bRunning) {
		//handle the event loop
		SDL_Event event;

		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					bRunning = false;
					break;
			}
		}

		//proc
		DrawShape();

		//flip the buffers
		SDL_GL_SwapBuffers();
	}

	SDL_Quit();
	return 0;
}

//-------------------------
//Function definitions
//-------------------------

void InitSDL() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		cerr << "Failed to init SDL" << endl;
		exit(1);
	}

	InitOpenGLAttributes();

	if (SDL_SetVideoMode(WIDTH, HEIGHT, BPP, FLAGS) == NULL) {
		cerr << "Failed to init the screen" << endl;
		exit(1);
	}
}

void InitOpenGL() {
	/* I don't understand alot of this code
	 * Anything I don't understand 100% is marked with a -?
	*/

	//shading model Gouraud (smooth) -?
	glShadeModel(GL_SMOOTH);

	//culling (complicated, disabled for now)
//	glCullFace(GL_BACK);
//	glFrontFace(GL_CCW);
//	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);

	//viewport
	glClearColor(0, 0, 0, 0);
	glViewport(0, 0, WIDTH, HEIGHT);

	glMatrixMode( GL_PROJECTION ); //matrix -?
	glLoadIdentity();

	//perspective
	gluPerspective(60.0, (double)(WIDTH)/(double)(HEIGHT), 1.0, 1024.0); //shortcut, avoidinng the other one
}

void InitOpenGLAttributes() {
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5); //-awkward numbers -?
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
}

void DrawShape() {
	//Clear the color and depth buffers
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	//We don't want to modify the projection matrix -?
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//draw my stuff

	//colours
	static GLubyte white[]	= {255, 255, 255, 255};
	static GLubyte black[]	= {0, 0, 0, 255};
	static GLubyte red[]	= {255, 0, 0, 255};
	static GLubyte yellow[]	= {255, 255, 0, 255};
	static GLubyte blue[]	= {0, 0, 255, 255};
	static GLubyte green[]	= {0, 255, 0, 255};

	//vertices
	static GLfloat v1[] = {-1.0f,  1.0f,  0.0f};
	static GLfloat v2[] = {-1.0f,  0.0f,  0.0f};
	static GLfloat v3[] = { 1.0f,  0.0f,  0.0f};
	static GLfloat v4[] = {-1.0f,  0.0f, -1.0f};

	//translation
	glTranslatef(0, -.5, -3);

	//rotation
	static float angle = 0.0f;
	glRotatef(angle, 0.0, 1.0, 0.0 ); //comment this out to disable the rotation

	if( (angle+=.1f) > 360.0f ) {
		angle = 0.0f;
	}

	//begin the shape, no culling
	glBegin(GL_TRIANGLES);

	//side 1
	DrawPoint(v1, green);
	DrawPoint(v2, red);
	DrawPoint(v3, yellow);

	//side 2
	DrawPoint(v1, green);
	DrawPoint(v2, red);
	DrawPoint(v4, blue);

	//side 3
	DrawPoint(v1, green);
	DrawPoint(v3, yellow);
	DrawPoint(v4, blue);

	//base
	DrawPoint(v2, red);
	DrawPoint(v3, yellow);
	DrawPoint(v4, blue);

	glEnd();
}

void DrawPoint(GLfloat* vert, GLubyte* col) {
	glColor4ubv(col);
	glVertex3fv(vert);
}
