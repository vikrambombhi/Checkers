//
//  Button.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "Button.h"
#include "Texture.h"

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
    spriteSheetTexture.render(buttonPoint.x, buttonPoint.y, &spriteClips[currentSprite]);
}

void Button::handleEvent(SDL_Event *event){
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
            //buttonClicked.render();
            printf("%i,%i\n",buttonPoint.x,buttonPoint.y);
        }
    }
}