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

	//init the screen
	SDL_Surface* pScreen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
	if (pScreen == NULL) {
		cerr << "Failed to initialise the  screen" << endl;
		return 1;
	}

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

		//draw to the screen
		SDL_Flip(pScreen);
	}

	SDL_Quit();

	return 0;
}
