//
//  SDL_util.h
//  Checkers
//
//  Created by Jacky Chiu on 2016-02-12.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef SDL_util_h
#define SDL_util_h

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int buttonWidth = 100;
const int buttonHeight = 100;

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;

bool init();
void closeWindow();

#endif /* SDL_util_h */


