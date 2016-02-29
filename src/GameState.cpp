//
//  GameState.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-25.
//  Copyright © 2016 Jacky Chiu. 
//

#include "GameState.h"
#include "CheckersBoard.h"
#include "Player.h"
#include "AI.h"
#include "Button.h"
#include "Texture.h"

const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 32;

GameState::GameState(){
    userQuit = false;
    Board = new CheckersBoard;
    boardButtons = new Button[TOTAL_BUTTONS];
    Player1 = new AI(true, Board, boardButtons);
    Player2 = new Player(false, Board, boardButtons);
    index = 0, column = 0, row = 0, value = 0;
}

GameState::~GameState(){
    delete Board;
    delete [] boardButtons;
    delete Player1;
    delete Player2;
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
        // Player make move //
        if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (Player2->selectingState == false) {
                for (int i=0; i<TOTAL_BUTTONS; i++) {
                    if (boardButtons[i].insideButton()) {
                        index = i;
                        // Player selects a piece to move //
                        Player2->selectPiece(&value, &column, &row, index);
                        break;
                    }
                }
            }
            else{
                for (int i=0; i<TOTAL_BUTTONS; i++) {
                    if (boardButtons[i].insideButton()) {
                        index = i;
                        // Player selects where the piece should move //
                        Player2->movePiece(value, column, row, index);
                        Player1->turn  = true;
                        Player2->turn = false;
                        break;
                    }
                }
            }
        }
    }
    // MAKE AI MOVE HERE //
    if(Player1->turn  == true){
        Player1->moveChoose();
        cout<<"AI made a move"<<endl;
        Player1->turn  = false;
        Player2->turn = true;
    }
}

bool GameState::loadMedia(){
    bool initSuccessfulful = true;
    
    if (!spriteSheetTexture.loadFromFile("data/CheckerSprite.png")) {
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

void GameState::stateUpdate(){
    return;
}

void GameState::stateRender(){
    
    // Render stuff here //
    
    Board->drawBoard();
    
    // Render whole team //
    index = 0;
    for (int y=0; y<8; y++) {
        for (int x=0; x<8; x++) {
            if((y+x)%2 == 1){
                boardButtons[index].renderBoardMember(*Board, x, y);
                index++;
            }
        }
    }
}

bool GameState::stateExit(){
    return userQuit;
}