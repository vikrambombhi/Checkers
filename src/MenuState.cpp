//
//  MenuState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu.
//

#include "../include/MenuState.h"

MenuState::MenuState(){
    currentStateEnum = MENU_STATE;
    nextStateEnum = MENU_STATE;
}

MenuState::~MenuState(){
    
}

void MenuState::stateEnter(){
    
}

void MenuState::stateEvent(){
    
}

StateEnum MenuState::stateUpdate(){
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
}

void MenuState::stateRender(){
    
}

bool MenuState::stateExit(){
    return false;
}

bool MenuState::loadMedia(){
    return false;
}