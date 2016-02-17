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
bool selectedState = false;

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

void Button::renderTeamMember(CheckersBoard Board, int x, int y){
    //renderButton = true;
    switch (Board.virtualBoard[x][y]) {
        case 1:
            currentSprite = RED_PIECE;
            render();
            break;
        case 2:
            currentSprite = BLACK_PIECE;
            render();
        default:
            break;
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
            //renderButton = true;
            if (selectedState == false) {
                selectedState = true;
            }
            else{
                buttonPoint.x = x;
                buttonPoint.y = y;
                selectedState = false;
            }
            //printf("%i,%i\n",buttonPoint.x,buttonPoint.y);
        }
    }
}