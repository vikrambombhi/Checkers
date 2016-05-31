//
//  GameState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-25.
//  Copyright © 2016 Jacky Chiu.
//

#ifndef GameState_h
#define GameState_h

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

#include "ApplicationState.h"
#include "Application.h"

enum SpriteList{
    EMPTY_PIECE,
    RED_PIECE,
    BLACK_PIECE,
    RED_KING,
    BLACK_KING,
    TOTAL_PIECES
};

class ApplicationStateManager;
class Button;
class CheckersBoard;
class Player;
class AI;
class Texture;

class GameState: public ApplicationState{
public:
    GameState();
    ~GameState();
    void stateEnter();
    void stateEvent();
    StateEnum stateUpdate();
    void stateRender();
    bool stateExit();
private:
    bool loadMedia();
    bool gameOver();
    CheckersBoard *Board;
    Button *boardButtons;
    Player *Player1;
    Player *Player2;
    bool userQuit;
};


#endif /* GameState_h */
