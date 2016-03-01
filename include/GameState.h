//
//  GameState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-25.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef GameState_h
#define GameState_h

#include "ApplicationState.h"
#include "GameObjects.h"

#ifdef _WIN32
#include <SDL.h>
#include<SDL_image.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

enum SpriteList{
    EMPTY_PIECE,
    RED_PIECE,
    BLACK_PIECE,
    TOTAL_PIECES
};

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
    void stateUpdate();
    void stateRender();
    bool stateExit();
private:
    bool loadMedia();
    CheckersBoard *Board;
    Button *boardButtons;
    AI *Player1;
    Player *Player2;
    SDL_Rect *spriteClips;
    Texture *spriteSheetTexture;
    bool userQuit;
    int index, column, row, value;
};

extern SpriteList currentSprite;
extern const int BUTTON_WIDTH;
extern const int BUTTON_HEIGHT;
extern const int TOTAL_BUTTONS;

#endif /* GameState_h */
