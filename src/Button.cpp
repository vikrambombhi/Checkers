//
//  Button.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "../include/Button.h"
#include "../include/Texture.h"

Button boardButtons[TOTAL_BUTTONS];

Button::Button(){
    buttonPoint.x = 0;
    buttonPoint.y = 0;
}

void Button::setPoint(int x, int y){
    buttonPoint.x = x;
    buttonPoint.y = y;
}

void Button::render(){
    //Render button with spritesheet
    if(renderButton){
        spriteSheetTexture.render(buttonPoint.x, buttonPoint.y, &spriteClips[currentSprite]);
    }
}

void Button::renderTeam(Player Player){
    for (int i=0; i<Player.team.size(); i++) {
        printf("hi");
    }
}

void Button::handleEvent(SDL_Event *event){
    
    // If clikced on do something //
    if(event->type == SDL_MOUSEBUTTONDOWN){
        
        int x,y;
        bool insideButton = true;
        SDL_GetMouseState(&x,&y);
        
        // Checks if button has been clicked
        // Above button //
        if(y < buttonPoint.y){
            insideButton = false;
        }
        // Under button //
        else if (y > buttonPoint.y + BUTTON_HEIGHT){
            insideButton = false;
        }
        // Left of button //
        else if (x < buttonPoint.x) {
            insideButton = false;
        }
        // Right of button //
        else if (x > buttonPoint.x + BUTTON_WIDTH){
            insideButton = false;
        }
        
        if (insideButton) {
            renderButton = true;
            //printf("%i,%i\n",buttonPoint.x,buttonPoint.y);
        }
        else{
            renderButton = false;
        }
    }
}