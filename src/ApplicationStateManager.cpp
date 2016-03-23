//
//  ApplicationStateManager.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-28.
//  Copyright © 2016 Jacky Chiu. 
//

#include "../include/ApplicationStateManager.h"
#include "../include/MenuState.h"
#include "../include/GameState.h"
#include "../include/GameOverState.h"

ApplicationStateManager::ApplicationStateManager(){
    currentState = new GameState();
    currentState->stateEnter();
}

ApplicationStateManager::~ApplicationStateManager(){
    delete currentState;
    currentState = NULL;
}

void ApplicationStateManager::stateEvent(){
    currentState->stateEvent();
}

StateEnum ApplicationStateManager::stateUpdate(){
    return currentState->stateUpdate();
}

void ApplicationStateManager::stateRender(){
    currentState->stateRender();
}

bool ApplicationStateManager::stateExit(){
    return currentState->stateExit();
}

void ApplicationStateManager::setCurrentStateEnum(StateEnum current){
    currentStateEnum = current;
}

StateEnum ApplicationStateManager::getCurrentStateEnum(){
    return currentStateEnum;
}

void ApplicationStateManager::changeStates(){
    switch (currentStateEnum) {
        case MENU_STATE:
            currentState = new MenuState;
            break;
        case GAME_STATE:
            currentState = new GameState();
            break;
        case GAME_OVER_STATE:
            currentState = new GameOverState;
            break;
        default:
            break;
    }
    currentState->stateEnter();
}