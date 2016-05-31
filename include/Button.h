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
#endif

#ifdef __APPLE__
#include <SDL2/SDL.h>
#endif

#ifdef __linux
#include <SDL2/SDL.h>
#endif

class Texture;

class Button{
public:
    Button();
    ~Button();
    void setPoint(int,int);
    bool insideButton(int,int);
    void render(int);
    int getButtonPointX();
    int getButtonPointY();
private:
    SDL_Point buttonPoint;
};

#endif /* Button_h */
