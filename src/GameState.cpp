//
//  GameState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-25.
//  Copyright © 2016 Jacky Chiu.
//
#include "../include/ApplicationStateManager.h"
#include "../include/GameState.h"
#include "../include/CheckersBoard.h"
#include "../include/Player.h"
#include "../include/AI.h"
#include "../include/RealPlayer.h"
#include "../include/Button.h"
#include "../include/Texture.h"

SDL_Rect spriteClips[TOTAL_PIECES-1];
Texture spriteSheetTexture;

SpriteList currentSprite;
const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 32;

GameState::GameState(){
    Board = new CheckersBoard;
    boardButtons = new Button[TOTAL_BUTTONS];
    Player1 = new AI(true, Board, boardButtons);
    Player2 = new RealPlayer(false, Board, boardButtons);
    //Player2 = new oldAI(false, Board, boardButtons);
    userQuit = false;
}

GameState::~GameState(){
    delete Board;
    Board = NULL;
    delete [] boardButtons;
    boardButtons = NULL;
    delete Player1;
    Player1 = NULL;
    delete Player2;
    Player2 = NULL;
}

void GameState::stateEnter(){
    if (!loadMedia()) {
        cout<<"Could not load media"<<endl;
    }
}

void GameState::stateEvent(){
    SDL_Event event;

    // Event loop //
    while(SDL_PollEvent(&event)!=0){

        // Quits game //
        if(event.type==SDL_QUIT)
        {
            userQuit=true;
        }

        // Player 1 turn //
        if (Player1->turn) {
            if(Player1->makeMove(&event)){
                Player1->updateKings();
                Player1->turn = false;
                Player2->turn = true;
                Player2->updateTeam();
                // Breaks to continue in main loop //
                break;
            }
        }
        // Player 2 turn //
        else{
            if(Player2->makeMove(&event)){
                Player2->updateKings();
                Player2->turn = false;
                Player1->turn = true;
                Player1->updateTeam();
                // Breaks to continue in main loop //
                break;
            }
        }
    }
}

bool GameState::loadMedia(){
    bool initSuccessfulful = true;

    if (!spriteSheetTexture.loadFromFile("data/CheckerSprites.png")) {
        printf("Could not load sprite");
        initSuccessfulful = false;
    }
    // Initalize Checkers Pieces //
    // Red Piece //
    spriteClips[0].x = 0;
    spriteClips[0].y = 0;
    spriteClips[0].w = BUTTON_WIDTH;
    spriteClips[0].h = BUTTON_HEIGHT;
    // Black Piece //
    spriteClips[1].x = BUTTON_WIDTH;
    spriteClips[1].y = 0;
    spriteClips[1].w = BUTTON_WIDTH;
    spriteClips[1].h = BUTTON_HEIGHT;
    // Red king Piece //
    spriteClips[2].x = BUTTON_WIDTH * 2;
    spriteClips[2].y = 0;
    spriteClips[2].w = BUTTON_WIDTH;
    spriteClips[2].h = BUTTON_HEIGHT;
    // Black king Piece //
    spriteClips[3].x = BUTTON_WIDTH * 3;
    spriteClips[3].y = 0;
    spriteClips[3].w = BUTTON_WIDTH;
    spriteClips[3].h = BUTTON_HEIGHT;

    int index = 0;
    bool indent = true;
    int xStart;

    // Sets points for buttons (top left of button)
    for(int y=0;y<SCREEN_HEIGHT;y+=BUTTON_HEIGHT){
        if (indent) {
            xStart = BUTTON_WIDTH;
            indent = false;
        }
        else{
            xStart = 0;
            indent = true;
        }
        for(int x=xStart;x<SCREEN_WIDTH;x+=2*BUTTON_WIDTH){
            boardButtons[index].setPoint(x, y);
            index++;
        }
    }
    return initSuccessfulful;
}

bool GameState::gameOver(){
    if (Player1->team.size() == 0 || Player2->team.size() == 0) {
        return true;
    }
    return false;
}

StateEnum GameState::stateUpdate(){
    if (gameOver()) {
        return GAME_OVER_STATE;
    }
    return GAME_STATE;
}

void GameState::stateRender(){

    // Render stuff here //
    // Light wood color //
    SDL_SetRenderDrawColor(gRenderer, 0xD4, 0x9A, 0x6A, 0xFF);
    // Refreshs screen //
    SDL_RenderClear(gRenderer);
    
    Board->drawBoard();

    // Render whole team //
    int index = 0;
    for (int y=0; y<8; y++) {
        for (int x=0; x<8; x++) {
            if((y+x)%2 == 1){
                Board->drawBoardPeices(x,y,&boardButtons[index]);
                index++;
            }
        }
    }
}

bool GameState::stateExit(){
    return userQuit;
}
