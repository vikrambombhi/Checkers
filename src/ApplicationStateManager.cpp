//
//  ApplicationStateManager.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-28.
//  Copyright © 2016 Jacky Chiu. 
//

#include "ApplicationStateManager.h"
#include "GameState.h"

ApplicationStateManager::ApplicationStateManager(){
    currentState = new GameState();
    currentState->stateEnter();
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