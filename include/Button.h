//
//  Button.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef Button_h
#define Button_h

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif
#include "Application.h"
#include "Player.h"
#include "CheckersBoard.h"
#include "Texture.h"

/*
const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 32;
*/
class CheckersBoard;

class Button: protected Application{
public:
    Button();
    void setPoint(int,int);
    bool insideButton();
    void render();
    void renderBoardMember(CheckersBoard,int,int);
    int getButtonPointX();
    int getButtonPointY();
private:
    SDL_Point buttonPoint;
    SDL_Rect spriteClips[TOTAL_PIECES-1];
    Texture spriteSheetTexture;
    SpriteList currentSprite;
};

//extern Button boardButtons[TOTAL_BUTTONS];

#endif /* Button_h */
