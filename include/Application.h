//
//  Application.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-18.
//  Copyright © 2016 Jacky Chiu. 
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

class ApplicationStateManager;

class Application{
public:
    Application();
    ~Application();
    int startApplication();
    bool init();
    void closeApplication();
protected:
    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    ApplicationStateManager *applicationStateManager;
};

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

#endif /* Application_h */
