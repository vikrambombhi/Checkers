//
//  Application.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-18.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef _WIN32
#include <SDL.h>
#include<SDL_image.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

using namespace std;

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Application{
public:
    Application();
    ~Application();
    bool init();
    bool loadMedia();
    void closeApplication();
};

#endif /* Application_h */
