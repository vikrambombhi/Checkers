//
//  MenuState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu.
//

#ifndef MenuState_h
#define MenuState_h

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include "ApplicationState.h"
#include "Application.h"
#include "Button.h"


class MenuState: public ApplicationState{
public:
    MenuState();
    ~MenuState();
    void stateEnter();
    void stateEvent();
    void stateUpdate();
    void stateRender();
    bool stateExit();
private:
    void drawMenu();
    bool loadMedia();
    bool userQuit;
    TTF_Font *font;
};


#endif /* MenuState_h */
