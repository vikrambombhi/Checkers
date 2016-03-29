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
#include "../include/oldAI.h"
#include "../include/RealPlayer.h"
#include "../include/Button.h"
#include "../include/Texture.h"

int TOTAL_BUTTONS = 32;


GameState::GameState(){
    BUTTON_WIDTH = 80;
    BUTTON_HEIGHT = 80;

    currentStateEnum = GAME_STATE;
    nextStateEnum = GAME_STATE;

    Board = new CheckersBoard;
    boardButtons = new Button[TOTAL_BUTTONS];

    userQuit = false;
    switch (GAMEMODE) {
        case 0:
            Player1 = new RealPlayer(true, Board, boardButtons);
            Player2 = new RealPlayer(false, Board, boardButtons);
            break;
        case 1:
            Player1 = new AI(true, Board, boardButtons);
            Player2 = new RealPlayer(false, Board, boardButtons);
            break;
        case 2:
            Player1 = new AI(true, Board, boardButtons);
            Player2 = new AI(false, Board, boardButtons);
            break;
        default:
            userQuit = true;
            break;
    }
    //Player2 = new oldAI(false, Board, boardButtons);

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
    spriteClips.clear();
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

        if (!gameOver()) {
            // Player 1 turn //
            if (Player1->turn) {
                if(Player1->makeMove(&event)){
                    Player1->updateKings();
                    Player1->turn = false;
                    Player2->turn = true;
                    Player2->updateTeam();
                    Player1turn++;
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
                    Player2turn++;
                    // Breaks to continue in main loop //
                    break;
                }
            }
        }
        else{
            nextStateEnum = GAME_OVER_STATE;
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
    SDL_Rect redPeice = {0,0,BUTTON_WIDTH,BUTTON_HEIGHT};
    spriteClips.push_back(redPeice);
    // Black Piece //
    SDL_Rect blackPeice = {BUTTON_WIDTH,0,BUTTON_WIDTH,BUTTON_HEIGHT};
    spriteClips.push_back(blackPeice);
    // Red king Piece //
    SDL_Rect redKing = {BUTTON_WIDTH * 2, 0, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips.push_back(redKing);
    // Black king Piece //
    SDL_Rect blackKing = {BUTTON_WIDTH * 3, 0, BUTTON_WIDTH, BUTTON_HEIGHT};
    spriteClips.push_back(blackKing);

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
    return true;
    if (Player1->team.size() == 0 || Player2->team.size() == 0) {
        return true;
    }
    return false;
}

StateEnum GameState::stateUpdate(){
    if (currentStateEnum != nextStateEnum) {
        return nextStateEnum;
    }
    return currentStateEnum;
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
