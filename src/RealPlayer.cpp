//
//  RealPlayer.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-03-02.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "RealPlayer.h"
#include "GameState.h"

RealPlayer::RealPlayer(bool topSide, CheckersBoard *board, Button *buttons): Player(topSide, board, buttons){
    index = 0, column = 0, row = 0, value = 0;
    selectingState = false;
    currentPieceIndex = 0;
}

RealPlayer::~RealPlayer(){
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

bool RealPlayer::makeMove(SDL_Event* event){
    
    if (event->type == SDL_MOUSEBUTTONDOWN) {
        
        if (!selectingState) {
            for (int i=0; i<TOTAL_BUTTONS; i++) {
                if (boardButtons[i].insideButton(BUTTON_HEIGHT,BUTTON_WIDTH)) {
                    index = i;
                    // Player selects a piece to move //
                    selectPiece();
                    currentPieceIndex = pieceTeamIndexByXY(boardButtons[i].getButtonPointX()/80, boardButtons[i].getButtonPointY()/80);
                    selectingState = true;
                    break;
                }
            }
        }
        else{
            for (int i=0; i<TOTAL_BUTTONS; i++) {
                if (boardButtons[i].insideButton(BUTTON_HEIGHT,BUTTON_WIDTH)) {
                    index = i;
                    // Player selects where the piece should move //
                    movePiece(currentPieceIndex,boardButtons[i].getButtonPointX()/80,boardButtons[i].getButtonPointY()/80);
                    selectingState = false;
                    return true;
                }
            }
        }
    }
    return false;
}

void RealPlayer::selectPiece(){
    // SELECT PIECE //
    // When a piece hasn't been selected yet, and the button currently selected doesn't have a piece inside //
    switch (Board->virtualBoard[boardButtons[index].getButtonPointX()/80][boardButtons[index].getButtonPointY()/80]) {
        case 0:
            cout<<"Selected button isn't a piece"<<endl;
            break;
        case 1:
            column = boardButtons[index].getButtonPointX()/80;
            row = boardButtons[index].getButtonPointY()/80;
            value = Board->virtualBoard[column][row];
            selectingState = true;
            break;
        case 2:
            cout<<"Piece isn't apart of your team"<<endl;
            break;
        default:
            break;
    }
}
