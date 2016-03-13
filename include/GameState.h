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
#include<SDL_image.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#endif

#include "ApplicationState.h"

enum SpriteList{
    EMPTY_PIECE,
    RED_PIECE,
    BLACK_PIECE,
    RED_KING,
    BLACK_KING,
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
    Player *Player1;
    Player *Player2;
    bool userQuit;
};

extern SDL_Rect spriteClips[TOTAL_PIECES-1];
extern Texture spriteSheetTexture;

extern SpriteList currentSprite;
extern const int BUTTON_WIDTH;
extern const int BUTTON_HEIGHT;
extern const int TOTAL_BUTTONS;

#endif /* GameState_h */
