/* File Name: xFramework.c
 * Author: Kayne Ruse
 * Date: 28/4/2012
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
 *     This is a simple framework written in C, based on Simple DirectMedia Layer (SDL).
 *     This framework contains no initialisation or rendering code.
*/
#include "xFramework.h"

/* Preprocessor directives */
#define LIST_02(X) X,X
#define LIST_04(X) LIST_02(X),LIST_02(X)
#define LIST_08(X) LIST_04(X),LIST_04(X)
#define LIST_16(X) LIST_08(X),LIST_08(X)
#define LIST_32(X) LIST_16(X),LIST_16(X)

#define FALSE 0
#define TRUE 1

/* xFramework internals */
int g_bRunning = TRUE;

xBasicCallback g_fpInit = NULL;
xBasicCallback g_fpQuit = NULL;

xBasicCallback g_fpHead = NULL;
xBasicCallback g_fpTail = NULL;
xBasicCallback g_fpUpdate = NULL;
xBasicCallback g_fpRender = NULL;

xEventCallback g_fpEvents[SDL_NUMEVENTS] = {LIST_32(NULL)};

/* xFramework functions */
int  xSetInitCallback(xBasicCallback cb) {
	if (g_fpInit != NULL) return 1;
	g_fpInit = cb;
	return 0;
}

int xSetQuitCallback(xBasicCallback cb) {
	if (g_fpQuit != NULL) return 1;
	g_fpQuit = cb;
	return 0;
}

int xSetHeadCallback(xBasicCallback cb) {
	if (g_fpHead != NULL) return 1;
	g_fpHead = cb;
	return 0;
}

int xSetTailCallback(xBasicCallback cb) {
	if (g_fpTail != NULL) return 1;
	g_fpTail = cb;
	return 0;
}

int xSetUpdateCallback(xBasicCallback cb) {
	if (g_fpUpdate != NULL) return 1;
	g_fpUpdate = cb;
	return 0;
}

int xSetRenderCallback(xBasicCallback cb) {
	if (g_fpRender != NULL) return 1;
	g_fpRender = cb;
	return 0;
}

int xSetEventCallback(xEventCallback cb, Uint8 e) {
	if (e >= SDL_NUMEVENTS) return 2;
	if (g_fpEvents[e] != NULL) return 1;
	g_fpEvents[e] = cb;
	return 0;
}

void xProc() {
	SDL_Event event;

	if (g_fpInit != NULL) g_fpInit();

	while(g_bRunning) {
		if (g_fpHead != NULL) g_fpHead();

		while(SDL_PollEvent(&event)) {
			if (g_fpEvents[event.type] != NULL)
				g_fpEvents[event.type](&event);
		}

		if (g_fpUpdate != NULL) g_fpUpdate();
		if (g_fpRender != NULL) g_fpRender();

		if (g_fpTail != NULL) g_fpTail();
	}

	if (g_fpQuit != NULL) g_fpQuit();
}

void xQuit() {
	g_bRunning = FALSE;
}
