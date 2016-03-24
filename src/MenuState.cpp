//
//  MenuState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu.
//

#include "../include/MenuState.h"
#include "../include/Texture.h"

//Texture spriteSheetTexture;
//vector<SDL_Rect> spriteClips;

MenuState::MenuState(){
    spriteClips.clear();
    currentStateEnum = MENU_STATE;
    nextStateEnum = MENU_STATE;
    userQuit = false;
}

MenuState::~MenuState(){
    spriteSheetTexture.free();
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
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
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
    bool initSuccessfulful = true;
    
    if (!spriteSheetTexture.loadFromFile("data/MenuState.png")) {
        printf("Could not load sprite");
        initSuccessfulful = false;
    }
    
    
    //SpriteClips
    
    SDL_Rect localMultiplayer = {0, 0, 346, 40};
    spriteClips.push_back(localMultiplayer);
    SDL_Rect localMultiplayerHover = {346, 0, 346, 40};
    spriteClips.push_back(localMultiplayerHover);
    SDL_Rect singlePlayer = {0, 40, 346, 40};
    spriteClips.push_back(singlePlayer);
    SDL_Rect singlePlayerHover = {346, 40, 346, 40};
    spriteClips.push_back(singlePlayerHover);
    SDL_Rect aI = {0, 80, 346, 40};
    spriteClips.push_back(aI);
    SDL_Rect aIHover = {346, 80, 346, 40};
    spriteClips.push_back(aIHover);
    SDL_Rect fullMenu = {0, 120, 640, 640};
    spriteClips.push_back(fullMenu);
    
    return initSuccessfulful;
}

void MenuState::drawMenu() {
    spriteSheetTexture.render(0, 0, &spriteClips[6]);
    
}






