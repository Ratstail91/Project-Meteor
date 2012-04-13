/* File Name: main.cpp
 * Copyright: (c) Kayne Ruse, all rights reserved.
 * Author: Kayne Ruse
 * Date: 
 * Description: Empty shell.
*/
#include <iostream>
#include "SDL.h"
using namespace std;



int SDL_main(int, char**) {
	//init SDL
	if (SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "Failed to initialise SDL" << endl;
		return 1;
	}

	//init OpenGL
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5); //funky numbers? what do these do?
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	//init the screen
	if (SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_OPENGL) == NULL) {
		cerr << "Failed to initialise the  screen" << endl;
		return 1;
	}

	//program loop
	bool bRunning = true;

	while(bRunning) {
		SDL_Event event;

		while(SDL_PollEvent(&event)) {
			switch(event.type) {
				case SDL_QUIT:
					bRunning = false;
					break;
			}
		}

		//proc
		//

		//draw to the screen
		SDL_GL_SwapBuffers();
	}

	SDL_Quit();

	return 0;
}
