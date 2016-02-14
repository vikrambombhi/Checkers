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

const int buttonWidth = 80;
const int buttonHeight = 80;

class Button{
public:
    Button();
    void setPoint(int,int);
    void render();
private:
    SDL_Point buttonPoint;
};

#endif /* Button_h */
