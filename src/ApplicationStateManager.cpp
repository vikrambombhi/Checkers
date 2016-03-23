//
//  ApplicationStateManager.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-28.
//  Copyright © 2016 Jacky Chiu. 
//

#include "../include/ApplicationStateManager.h"
#include "../include/GameState.h"
#include "../include/MenuState.h"


ApplicationStateManager::ApplicationStateManager(){
    currentState = new MenuState;
    currentState->stateEnter();
}

ApplicationStateManager::~ApplicationStateManager(){
    currentState = NULL;
}

void ApplicationStateManager::stateEnter(){
    currentState->stateEnter();
}

void ApplicationStateManager::stateEvent(){
    currentState->stateEvent();
}

void ApplicationStateManager::stateUpdate(){
    currentState->stateUpdate();
}

void ApplicationStateManager::stateRender(){
    currentState->stateRender();
}

bool ApplicationStateManager::stateExit(){
    return currentState->stateExit();
}