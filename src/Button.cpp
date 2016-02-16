//
//  Button.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "../include/Button.h"
#include "../include/Texture.h"
#include "../include/CheckersBoard.h"

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

void Button::renderTeam(Player Player,int index){
    // Things are switched around idk why SOMEONE CHECK THESE//
    if (Player.topSide) {
        currentSprite = BLACK_PIECE;
    }
    else{
        currentSprite = RED_PIECE;
    }
    renderButton = true;
    buttonPoint.x = BUTTON_WIDTH*Player.team[index].x;
    buttonPoint.y = BUTTON_HEIGHT*Player.team[index].y;
    render();

}

void Button::handleEvent(SDL_Event *event, int index){
    
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
            
            Board.printBoard();
            
        }
        else{
            renderButton = false;
        }
    }
}