//
//  Player.cpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. 
//

#include "../include/Player.h"
#include "../include/CheckersBoard.h"
#include "../include/Button.h"
#include "GameState.h"

Player::Player(bool topSide, CheckersBoard *board, Button buttons[]){
    Board = board;
    boardButtons = buttons;
    initTeam(topSide);
    if (topSide) {
        turn = false;
    }
    else{
        turn = true;
    }
    selectingState = false;
}

Player::~Player(){
    team.clear();
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

void Player::initTeam(bool topSide) {
    if (topSide) {
        //----------------------------BLACK TEAM----------------------------\\
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 0
        team[0].x = 1;
        team[0].y = 0;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 1
        team[1].x = 3;
        team[1].y = 0;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 2
        team[2].x = 5;
        team[2].y = 0;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 3
        team[3].x = 7;
        team[3].y = 0;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 4
        team[4].x = 0;
        team[4].y = 1;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 5
        team[5].x = 2;
        team[5].y = 1;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 6
        team[6].x = 4;
        team[6].y = 1;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 7
        team[7].x = 6;
        team[7].y = 1;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 8
        team[8].x = 1;
        team[8].y = 2;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 9
        team[9].x = 3;
        team[9].y = 2;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 10
        team[10].x = 5;
        team[10].y = 2;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 11
        team[11].x = 7;
        team[11].y = 2;
    }
    else {
        //-----------------------------RED TEAM----------------------------\\
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 0
        team[0].x = 0;
        team[0].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 1
        team[1].x = 2;
        team[1].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 2
        team[2].x = 4;
        team[2].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 3
        team[3].x = 6;
        team[3].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 4
        team[4].x = 1;
        team[4].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 5
        team[5].x = 3;
        team[5].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 6
        team[6].x = 5;
        team[6].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 7
        team[7].x = 7;
        team[7].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 8
        team[8].x = 0;
        team[8].y = 5;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 9
        team[9].x = 2;
        team[9].y = 5;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 10
        team[10].x = 4;
        team[10].y = 5;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 11
        team[11].x = 6;
        team[11].y = 5;
    }

        // Update Virtual board after init //

    for (int teamIndex = 0; teamIndex < TEAM_SIZE; teamIndex++) {
        Board->virtualBoard[team[teamIndex].x][team[teamIndex].y] = topSide + 1;
    }
}

void Player::selectPiece(int *value, int *column, int *row, int index){
    // SELECT PIECE //
    // When a piece hasn't been selected yet, and the button currently selected doesn't have a piece inside //
    switch (Board->virtualBoard[boardButtons[index].getButtonPointX()/80][boardButtons[index].getButtonPointY()/80]) {
        case 0:
            cout<<"Selected button isn't a piece"<<endl;
            break;
        case 1:
            *column = boardButtons[index].getButtonPointX()/80;
            *row = boardButtons[index].getButtonPointY()/80;
            *value = Board->virtualBoard[*column][*row];
            selectingState = true;
            break;
        case 2:
            cout<<"Piece isn't apart of your team"<<endl;
            break;
        default:
            break;
    }
}

void Player::movePiece(int teamIndex, int moveCommand) {
    // Moves piece
    int yDirectionMultiplier = 1, xDirectionMultiplier = 1, teamColor = RED_PIECE, oppositeTeamColor = BLACK_PIECE;
    if (topSide) {
        yDirectionMultiplier *= -1;
        teamColor = BLACK_PIECE;
        oppositeTeamColor = RED_PIECE;
    }
    if (moveCommand > 1) {
        yDirectionMultiplier *= -1;
        moveCommand -= 2;
    }
    if (moveCommand == 0) {
        xDirectionMultiplier *= -1;
    }
    int newY = team[teamIndex].y + yDirectionMultiplier;
    int newX = team[teamIndex].x + xDirectionMultiplier;
    
    if (Board->virtualBoard[newX][newY] == oppositeTeamColor) {
        killPiece(newX, newY);
        newY += yDirectionMultiplier;
        newX += xDirectionMultiplier;
    }
    
    Board->virtualBoard[newX][newY] = teamColor;
    Board->virtualBoard[team[teamIndex].x][team[teamIndex].y] = EMPTY_PIECE;
    team[teamIndex].x = newX;
    team[teamIndex].y = newY;
    
}

void Player::killPiece(int x, int y) {
    Board->virtualBoard[x][y] = 0;
}


int Player::pieceTeamIndexByXY(int x, int y) {
    int index=0;
    for(;index<TEAM_SIZE;index++){
        if((team[index].x == x) && (team[index].y == y)){
            break;
        }
    }
    return index;
}
