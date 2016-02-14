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

#ifdef _WIN32
    #include <SDL.h>
#elif __APPLE__
    #include <SDL2/SDL.h>
#endif


const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;

bool init();
void closeWindow();

#endif /* SDL_util_h */


