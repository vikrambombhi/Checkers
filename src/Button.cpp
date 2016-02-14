//
//  Button.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "Button.h"

SDL_Rect SpriteClips[TOTAL_PIECES];
Button boardButtons[TOTAL_BUTTONS];
Sprites currentSprite;

Button::Button(){
    buttonPoint.x = 0;
    buttonPoint.y = 0;
}

void Button::setPoint(int x, int y){
    buttonPoint.x = x;
    buttonPoint.y = y;
}

void Button::render(){
    //Render Spritsheet
}