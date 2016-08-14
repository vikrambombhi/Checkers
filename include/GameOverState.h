//
//  GameOverState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-03-23.
//  Copyright © 2016 Jacky Chiu.

#ifndef GameOverState_h
#define GameOverState_h

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#endif

#ifdef __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#endif

#ifdef __linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#endif

#include "ApplicationState.h"
#include "Application.h"

class Button;

enum EndSpriteEnum {
    END_MENU,
    END_FULL_MENU
};


class GameOverState: public ApplicationState{
public:
    GameOverState();
    ~GameOverState();
    void stateEnter();
    void stateEvent();
    StateEnum stateUpdate();
    void stateRender();
    bool stateExit();
private:
    bool hover[1] = {false};
    Button *boardButtons;
    void drawMenu();
    bool loadMedia();
    bool userQuit;
};


#endif /* MenuState_h */
