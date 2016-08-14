#include "../include/GameOverState.h"
#include "../include/Texture.h"
#include "../include/Button.h"

GameOverState::GameOverState(){
    BUTTON_WIDTH = 346;
    BUTTON_HEIGHT = 40;
    currentStateEnum = GAME_OVER_STATE;
    nextStateEnum = GAME_OVER_STATE;
    boardButtons = new Button[END_FULL_MENU];
    userQuit = false;

}

GameOverState::~GameOverState(){
    delete [] boardButtons;
    boardButtons = NULL;
    spriteSheetTexture.free();
    spriteClips.clear();
}

void GameOverState::stateEnter(){
    if (!loadMedia()) {
        cout<<"Could not load media"<<endl;
    }
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

        if (event.type == SDL_MOUSEMOTION) {
            // Checks if mouse is hovering over a button
            for (int index = 0; index < 1; index ++) {
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
            for (int index = 0; index < 1; index++) {
                if (hover[index]) {
                    nextStateEnum = GAME_STATE;
                    GAMEMODE = index;
                }
            }
        }
    }
}

StateEnum GameOverState::stateUpdate(){
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
}

void GameOverState::stateRender(){
    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(gRenderer);
    drawMenu();
    for (int index = 0; index < 1; index++) {
        currentSprite = index;
        if (hover[index]) {
            currentSprite += 1;
        }
        boardButtons[index].render(currentSprite);
    }
}

bool GameOverState::stateExit(){
    return userQuit;
}

bool GameOverState::loadMedia(){
    bool initSuccessfulful = true;

    if (!spriteSheetTexture.loadFromFile("data/GameOverState.png")) {
        printf("Could not load sprite");
        initSuccessfulful = false;
    }


    // SpriteClips
    // Standard Clips
    SDL_Rect mainMenu = {0, 80, 346, 40};
    spriteClips.push_back(mainMenu);
    // Hover Clips
    SDL_Rect mainMenuHover = {346, 80, 346, 40};
    spriteClips.push_back(mainMenuHover);
    // Full Menu
    SDL_Rect fullMenu = {0, 120, 640, 640};
    spriteClips.push_back(fullMenu);

    boardButtons[END_MENU].setPoint(167, 400);

    return initSuccessfulful;
}

void GameOverState::drawMenu() {
    spriteSheetTexture.render(0, 0, &spriteClips[2]);
}
