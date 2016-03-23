//
//  GameOverState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-03-23.
//  Copyright © 2016 Jacky Chiu.
//
#include <stdio.h>
#include "../include/GameOverState.h"
#include "../include/Texture.h"

GameOverState::GameOverState(){
    userQuit = false;
}

GameOverState::~GameOverState(){
    
}

void GameOverState::stateEnter(){
    printf("GAME OVER");
}

void GameOverState::stateEvent(){
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

StateEnum GameOverState::stateUpdate(){
    return GAME_OVER_STATE;
}

void GameOverState::stateRender(){
    // Light wood color //
    SDL_SetRenderDrawColor(gRenderer, 0xD4, 0x9A, 0x6A, 0xFF);
    // Refreshs screen //
    SDL_RenderClear(gRenderer);
}

bool GameOverState::stateExit(){
    return userQuit;
}

bool GameOverState::loadMedia(){
    return false;
}