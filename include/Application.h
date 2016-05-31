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
#include <vector>

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#endif

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

#ifdef __linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif


using namespace std;

class ApplicationStateManager;
class Texture;

class Application{
public:
    Application();
    ~Application();
    int startApplication();
    bool init();
    void closeApplication();
    int gameMode;
protected:
    ApplicationStateManager *applicationStateManager;
};

extern vector<SDL_Rect> spriteClips;
extern Texture spriteSheetTexture;
extern int currentSprite;

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int BUTTON_WIDTH;
extern int BUTTON_HEIGHT;
extern int TOTAL_BUTTONS;

extern int GAMEMODE;

#endif /* Application_h */
