//
//  Button.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef Button_h
#define Button_h

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif
#include "Game.h"
#include "Player.h"
#include "CheckersBoard.h"
/*
const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 32;
*/
class CheckersBoard;

class Button: public Game{
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
};

extern Button boardButtons[TOTAL_BUTTONS];

#endif /* Button_h */
