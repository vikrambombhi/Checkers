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
#include "Player.h"
#include "CheckersBoard.h"

const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 32;

class Player;
class CheckersBoard;

class Button{
public:
    Button();
    void setPoint(int,int);
    void handleEvent(SDL_Event*);
    void render();
    void renderTeamMember(CheckersBoard,int,int);
private:
    SDL_Point buttonPoint;
};

extern Button boardButtons[TOTAL_BUTTONS];
extern bool selectedState;
#endif /* Button_h */
