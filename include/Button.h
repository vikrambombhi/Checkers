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
#include "GameState.h"

class CheckersBoard;
class Texture;

class Button{
public:
    Button();
    ~Button();
    void setPoint(int,int);
    bool insideButton();
    void render();
    int getButtonPointX();
    int getButtonPointY();
private:
    SDL_Point buttonPoint;
};

//extern Button boardButtons[TOTAL_BUTTONS];

#endif /* Button_h */
