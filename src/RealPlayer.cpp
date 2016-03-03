//
//  RealPlayer.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-03-02.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "../include/RealPlayer.h"
#include "../include/GameState.h"

RealPlayer::RealPlayer(bool topSide, CheckersBoard *board, Button *buttons): Player(topSide, board, buttons){
    buttonIndex = 0, xLocation = 0, yLocation = 0;
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
            for (int index=0; index<TOTAL_BUTTONS; index++) {
                if (boardButtons[index].insideButton(BUTTON_HEIGHT,BUTTON_WIDTH)) {
                    buttonIndex = index;
                    // Player selects a piece to move //
                    selectPiece(boardButtons[buttonIndex].getButtonPointX()/80, boardButtons[buttonIndex].getButtonPointY()/80);
                    break;
                }
            }
        }
        else{
            for (int index=0; index<TOTAL_BUTTONS; index++) {
                if (boardButtons[index].insideButton(BUTTON_HEIGHT,BUTTON_WIDTH)) {
                    buttonIndex = index;
                    // Player selects where the piece should move //
                    movePiece(currentPieceIndex, boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80);
                    selectingState = false;
                    return true;
                }
            }
        }
    }
    return false;
}

void RealPlayer::selectPiece(int x, int y){
    // SELECT PIECE //
    // When a piece hasn't been selected yet, and the button currently selected doesn't have a piece inside //
    
    if (Board->virtualBoard[x][y] == teamNumberOnVirtualBoard) {
        xLocation = x;
        yLocation = y;
        currentPieceIndex = pieceTeamIndexByXY(x, y);
        selectingState = true;
    }
    else{
        cout<<"Pick proper piece"<<endl;
    }
}

void RealPlayer::selectLocation(int x, int y) {
}
