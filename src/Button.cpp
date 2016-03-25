//
//  Button.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. 
//

#include "../include/Button.h"
#include "../include/GameState.h"
#include "../include/Texture.h"
#include "../include/Application.h"

Button::Button(){
    buttonPoint.x = 0;
    buttonPoint.y = 0;
}

Button::~Button(){
    buttonPoint.x = NULL;
    buttonPoint.y = NULL;
}

void Button::setPoint(int x, int y){
    buttonPoint.x = x;
    buttonPoint.y = y;
}

void Button::render(int sprite){
    //Render button with spritesheet
    spriteSheetTexture.render(buttonPoint.x, buttonPoint.y, &spriteClips[sprite]);
}

bool Button::insideButton(int buttonWidth, int buttonHeight){

    int x,y;
    bool insideButton = true;
    SDL_GetMouseState(&x,&y);
    
    // Above button //
    if(y < buttonPoint.y){
        insideButton = false;
    }
    // Under button //
    else if (y > buttonPoint.y + buttonHeight){
        insideButton = false;
    }
    // Left of button //
    else if (x < buttonPoint.x) {
        insideButton = false;
    }
    // Right of button //
    else if (x > buttonPoint.x + buttonWidth){
        insideButton = false;
    }

    return insideButton;
}

int Button::getButtonPointX(){
    return buttonPoint.x;
}

int Button::getButtonPointY(){
    return buttonPoint.y;
}