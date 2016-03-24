//
//  MenuState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu.
//

#include "../include/MenuState.h"

MenuState::MenuState(){
    userQuit = false;
}

MenuState::~MenuState(){
    
}

void MenuState::stateEnter(){
    if (!loadMedia()) {
        cout<<"Could not load media"<<endl;
    }
}

void MenuState::stateEvent(){
    SDL_Event event;
    
    // Event loop //
    while(SDL_PollEvent(&event)!=0){
        
        // Quits game //
        if(event.type==SDL_QUIT)
        {
            userQuit=true;
        }

    }
}

StateEnum MenuState::stateUpdate(){
    //return GAME_STATE;
    return MENU_STATE;
}

void MenuState::stateRender(){
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    
    drawMenu();
}

bool MenuState::stateExit(){
    return userQuit;
}

bool MenuState::loadMedia(){
    
    
    return true;
}

void MenuState::drawMenu() {

    
}






