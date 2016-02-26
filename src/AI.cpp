#include<iostream>
#include <cstdlib>
#include "../include/AI.h"
#include "../include/Texture.h"

AI::AI(bool topSide): Player(topSide){
}

struct bestKill{
 int leftVright;
 int killPotential;
}bestKill;

int EMPTYSQUARE = 0;

/*
void AI::movePiece(int neo_x, int neo_y){
    // LOLZ PLZ WORK//
    if((Board.virtualBoard[neo_x][neo_y] == 2) && (Board.virtualBoard[bestMove.x][bestMove.y] == 0)){
        Board.virtualBoard[bestMove.x][bestMove.y] = 2;
        Board.virtualBoard[neo_x][neo_y] = 0;
    }
    for(int b=0;b<TEAM_SIZE;b++){
            if((team[b].x == neo_x) && (team[b].y == neo_y)){
                team[b].x = bestMove.x;
                team[b].y = bestMove.y;
               }
        }
    Board.printBoard();
}
*/

int AI::threatCheckLeft(int x, int y){
    if(Board.virtualBoard[x-1][y+1] == RED_PIECE){
        return 1;
    }
    if(Board.virtualBoard[x-1][y+1] == BLACK_PIECE){
        return 2;
    }
    if(Board.virtualBoard[x-1][y+1] == EMPTYSQUARE){
        return 0;
    }
}

int AI::threatCheckRight(int x, int y){
    if(Board.virtualBoard[x+1][y+1] == RED_PIECE){
        return RED_PIECE;
    }
    if(Board.virtualBoard[x+1][y+1] == BLACK_PIECE){
        return BLACK_PIECE;
    }
    if(Board.virtualBoard[x+1][y+1] == EMPTYSQUARE){
        return EMPTYSQUARE;
    }
}

int AI:: checkLeft(int x, int y){
    int left;
    if(Board.virtualBoard[x-1][y+1] == EMPTYSQUARE){
        left = left+1;
        if(threatCheckLeft(x-1, y+1) == RED_PIECE){
            left = left-1;
        }
        if(threatCheckRight(x-1, y+1) == RED_PIECE){
            left = left-1;
        }
    }
    if(Board.virtualBoard[x+1][y+1] == 0){
        left=left+1;
        if(threatCheckLeft(x+1, y+1) == RED_PIECE){
            left = left-1;
        }
        if(threatCheckRight(x+1, y+1) == RED_PIECE){
            left = left-1;
        }
    }
    return left;
}

int AI:: checkRight(int x, int y){
    int right;
    if(Board.virtualBoard[x-1][y+1] == 0){
        right = right+1;
    }
    if(Board.virtualBoard[x+1][y+1] == 0){
        right = right+1;
    }
    return right;
}


void AI::moveCheck(int x, int y, int b){
    int left = checkLeft(x-1, y+1);
    int right = checkRight(x+1, y+1);
    cout<< "left: " << left << " " << "Right: " << right << endl;
    /*
    if(left>=right){
        team[b].probability = left;
        team[b].leftVright = 0;
    }
    if(right>left){
        team[b].probability = right;
        bestKill.leftVright = 1;
    }
    */
}

void AI::moveChoose(){
    cout<<"AI's Turn"<<endl;
    for(int b=0;b<12;b++){
        moveCheck(team[b].x, team[b].y, b);
    }
    /*
    int temp = 0;
    int neo_x;
    int neo_y;
    for(int b=0;b<team.size();b++){
        if(team[b].probability>temp) {
            temp = team[b].probability;
            neo_x = team[b].x;
            neo_y = team[b].y;
        }
    }
    cout<< "the chosen one" << neo_x << "," << neo_y << "best move" << bestMove.x << "," << bestMove.y << endl;
    movePiece(neo_x, neo_y);
    */
}
