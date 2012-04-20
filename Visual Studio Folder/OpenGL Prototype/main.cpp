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
 *     //...
*/
#include <iostream>
#include "SDL.h"
#include "xFramework.h"
using namespace std;

//-------------------------

void Init();
void Quit();
void Update();
void Render();

void KeyDown(SDL_Event const*);
void KeyUp(SDL_Event const*);

SDL_Surface* g_pScreen;

//-------------------------

int SDL_main(int, char**) {
	xSetInitCallback(Init);
	xSetQuitCallback(Quit); //another possibility is xSetQuitCallback(SDL_Quit);
	xSetUpdateCallback(Update);
	xSetRenderCallback(Render);

	xSetEventCallback(KeyDown, SDL_KEYDOWN);
	xSetEventCallback(KeyUp, SDL_KEYUP);

	xProc();

	return 0;
}

//-------------------------

void Init() {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		cerr << "Failed to init video" << endl;
	}

	g_pScreen = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);

	if (g_pScreen == NULL) {
		cerr << "Failed to set video mode" << endl;
	}
}

void Quit() {
	SDL_Quit();
}

void Update() {
	//
}

void Render() {
	SDL_Flip(g_pScreen);
}

void KeyDown(SDL_Event const* const event) {
	switch(event->key.keysym.sym) {
		case SDLK_ESCAPE:
			xQuit();
			break;
	}
}

void KeyUp(SDL_Event const* event) {
	//
}