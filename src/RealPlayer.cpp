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
    xLocation = 0, yLocation = 0;
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
        
        // Selecting state for inital piece //
        if (!selectingState) {
            for (int index=0; index<TOTAL_BUTTONS; index++) {
                if (boardButtons[index].insideButton(BUTTON_HEIGHT,BUTTON_WIDTH)) {
                    // Player selects a piece to move //
                    selectPiece(boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80);
                    break;
                }
            }
        }
        // Selecting for the piece to be moved //
        else{
            for (int index=0; index<TOTAL_BUTTONS; index++) {
                if (boardButtons[index].insideButton(BUTTON_HEIGHT,BUTTON_WIDTH)) {
                    // Player selects where the piece should move //
                    if (selectedLocationIsValid(boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80)) {
                        movePiece(currentPieceIndex, boardButtons[index].getButtonPointX()/80, boardButtons[index].getButtonPointY()/80);
                        Board->turnHighLightOff();
                        return true;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

void RealPlayer::selectPiece(int x, int y){
    // SELECT PIECE //
    // When a piece hasn't been selected yet, and the button currently selected doesn't have a piece inside //
    if(Board->virtualBoard[x][y]==TEAM_NUMBER){
            xLocation = x;
            yLocation = y;
            currentPieceIndex = pieceTeamIndexByXY(x, y);
            Board->turnHighLightOn(x, y);
            selectingState = true;
            cout << "Selected piece is:\t(" << x << ", " << y << ")" <<endl;
    }
    else{
        cout<<"Piece isn't apart of your team"<<endl;
    }
}

bool RealPlayer::selectedLocationIsValid(int x, int y) {
    cout << "Selected location is:\t(" << x << ", " << y << ")" <<endl;
    bool locationIsValid = false;
    // realPlayer select only works for (topside == false) //
    if (Board->virtualBoard[x][y] == EMPTY_PIECE) {

        // case 1: moving in a 3x3 square centered at the origin //
        if (abs(x - xLocation) == 1 && abs(y - yLocation) == 1) {

            // case 1.1: piece is a king //
            if (team[currentPieceIndex].isKing()) {
                locationIsValid = true;
            }

            // case 1.2: piece isn't a king //
            else if (y - yLocation == ONE) {
                locationIsValid = true;
            }
        }

        // case 2: moving in a 5x5 square centered at the origin to kill a piece //
        else if (abs(x - xLocation) == 2 && abs(y - yLocation) == 2 && Board->virtualBoard[(x + xLocation)/2][(y + yLocation)/2] == ENEMY_TEAM_NUMBER) {

            // case 2.1: piece is a king //
            if (team[currentPieceIndex].isKing()) {
                locationIsValid = true;
            }

            // case 2.2: piece isn't a king //
            else if (y - yLocation == 2*ONE) {
                locationIsValid = true;
            }
        }
    }
    // case 3: selects own piece to switch selection //
    else if(Board->virtualBoard[x][y] == TEAM_NUMBER){
        selectPiece(x, y);
        locationIsValid = false;
    }
    if (!locationIsValid) {
        cout<<"cant move here"<<endl;
    }
    else{
        selectingState = false;
    }
    return locationIsValid;
}
