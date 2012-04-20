/* File Name: xFramework.h
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
 *     This is a simple framework written in C, based on Simple DirectMedia Layer (SDL).
 *     This framework contains no initialisation or rendering code.
*/
#ifndef KR_XFRAMEWORK_H_
#define KR_XFRAMEWORK_H_

/* Dependencies */
#include "SDL.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Callback types */
typedef void (*xBasicCallback)(void);
typedef void (*xEventCallback)(SDL_Event const);

/* xFramework functions */
int xSetInitCallback	(xBasicCallback);
int xSetQuitCallback	(xBasicCallback);
int xSetUpdateCallback	(xBasicCallback);
int xSetRenderCallback	(xBasicCallback);
int xSetEventCallback	(xEventCallback, Uint8);

void xProc();
void xQuit();

#ifdef __cplusplus
} //extern "C"
#endif

#endif
