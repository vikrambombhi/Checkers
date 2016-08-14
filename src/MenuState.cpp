//
//  MenuState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu.
//

#include "../include/MenuState.h"
#include "../include/Texture.h"
#include "../include/Button.h"

MenuState::MenuState(){
    BUTTON_WIDTH = 346;
    BUTTON_HEIGHT = 40;
    currentStateEnum = MENU_STATE;
    nextStateEnum = MENU_STATE;
    boardButtons = new Button[FULL_MENU];
    userQuit = false;

}

MenuState::~MenuState(){
    delete [] boardButtons;
    boardButtons = NULL;
    spriteSheetTexture.free();
    spriteClips.clear();
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

        if (event.type == SDL_MOUSEMOTION) {
            // Checks if mouse is hovering over a button
            for (int index = 0; index < 3; index ++) {
                if (boardButtons[index].insideButton(346, 40)) {
                    hover[index] = true;
                }
                else {
                    hover[index] = false;
                }
            }
        }

        // Checks if a button was clicked
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            for (int index = 0; index < 3; index++) {
                if (hover[index]) {
                    nextStateEnum = GAME_STATE;
                    GAMEMODE = index;
                }
            }
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
    for (int index = 0; index < 3; index++) {
        currentSprite = index;
        if (hover[index]) {
            currentSprite += 3;
        }
        boardButtons[index].render(currentSprite);
    }
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


    // SpriteClips
    // Standard Clips
    SDL_Rect localMultiplayer = {0, 0, 346, 40};
    spriteClips.push_back(localMultiplayer);
    SDL_Rect singlePlayer = {0, 40, 346, 40};
    spriteClips.push_back(singlePlayer);
    SDL_Rect aI = {0, 80, 346, 40};
    spriteClips.push_back(aI);
    // Hover Clips
    SDL_Rect localMultiplayerHover = {346, 0, 346, 40};
    spriteClips.push_back(localMultiplayerHover);
    SDL_Rect singlePlayerHover = {346, 40, 346, 40};
    spriteClips.push_back(singlePlayerHover);
    SDL_Rect aIHover = {346, 80, 346, 40};
    spriteClips.push_back(aIHover);
    // Full Menu
    SDL_Rect fullMenu = {0, 120, 640, 640};
    spriteClips.push_back(fullMenu);

    boardButtons[LOCAL_MULTIPLAYER].setPoint(148, 210);
    boardButtons[SINGLEPLAYER].setPoint(148, 280);
    boardButtons[AI_VS_AI].setPoint(148, 350);

    return initSuccessfulful;
}

void MenuState::drawMenu() {
    spriteSheetTexture.render(0, 0, &spriteClips[FULL_MENU]);
}
