#include<iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "../include/AI.h"
#include "../include/GameState.h"

AI::AI(bool topSide, CheckersBoard *board, Button *buttons): Player(topSide, board, buttons){
}

AI::~AI(){
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

void AI::movePiece(int x, int y, int newX, int newY){
    if((Board->virtualBoard[x][y] == BLACK_PIECE) && (Board->virtualBoard[newX][newY] == EMPTY_PIECE)){
        Board->virtualBoard[newX][newY] = BLACK_PIECE;
        Board->virtualBoard[x][y] = EMPTY_PIECE;
    }
    for(int b=0;b<team.size();b++){
            if((team[b].x == x) && (team[b].y == y)){
                team[b].x = newX;
                team[b].y = newY;
               }
        }
    cout<<*Board<<endl;
}

int AI::threatCheckLeft(int x, int y){
    if(x>0 && y<7){
        if(Board->virtualBoard[x-1][y+1] == RED_PIECE){
            return RED_PIECE;
        }
        if(Board->virtualBoard[x-1][y+1] == BLACK_PIECE){
            return BLACK_PIECE;
        }
        if(Board->virtualBoard[x-1][y+1] == EMPTY_PIECE){
            return EMPTY_PIECE;
        }
    }
    return -1;
}

int AI::threatCheckRight(int x, int y){
    if(x<7 && y <7){
        if(Board->virtualBoard[x+1][y+1] == RED_PIECE){
            return RED_PIECE;
        }
        if(Board->virtualBoard[x+1][y+1] == BLACK_PIECE){
            return BLACK_PIECE;
        }
        if(Board->virtualBoard[x+1][y+1] == EMPTY_PIECE){
            return EMPTY_PIECE;
        }
    }
    return -1;
}

int AI:: checkLeft(int x, int y,int left){
    if(x>0 && y<7 && Board->virtualBoard[x-1][y+1] == EMPTY_PIECE){
        left = left+1;
        if(threatCheckLeft(x, y) == RED_PIECE){
            left = left-1;
        }
        if(threatCheckRight(x, y) == RED_PIECE){
            left = left-1;
        }
    }
    if(x<7 && y<7 && Board->virtualBoard[x+1][y+1] == EMPTY_PIECE){
        left=left+1;
        if(threatCheckLeft(x, y) == RED_PIECE){
            left = left-1;
        }
        if(threatCheckRight(x, y) == RED_PIECE){
            left = left-1;
        }
    }
    else{
        left = left-1;
    }
    return left;
}

int AI:: checkRight(int x, int y,int right){
    if(x>0 && y<7 && Board->virtualBoard[x-1][y+1] == EMPTY_PIECE){
        right = right+1;
        if(threatCheckLeft(x-1, y+1) == RED_PIECE){
            right = right-1;
        }
        if(threatCheckRight(x-1, y+1) == RED_PIECE){
            right = right-1;
        }
    }
    if(x<7 && y<7 && Board->virtualBoard[x+1][y+1] == EMPTY_PIECE){
        right = right+1;
        if(threatCheckLeft(x+1, y+1) == RED_PIECE){
            right = right-1;
        }
        if(threatCheckRight(x+1, y+1) == RED_PIECE){
            right = right-1;
        }
    }
    else{
        right = right-1;
    }
    return right;
}


void AI::moveCheck(int x, int y, int b){
    int left;
    int right;
    if(x>1 && y<7 && threatCheckLeft(x, y) == EMPTY_PIECE){
        left = checkLeft(x-1, y+1, left);
    }
    else{
        left = -999999999;
    }
    if(x<6 && y<7 && threatCheckRight(x, y) == EMPTY_PIECE){
        right = checkRight(x+1, y+1, right);
    }
    else{
        right = -999999999;
    }
    if(x==1 && y<7){
        right = checkRight(x+1, y+1, right);
        left = -999999999;
    }
    if(x==6 && y<7){
        left = checkLeft(x-1, y+1, left);
        right = -999999999;
    }

    cout<< "left: " << left << " " << "Right: " << right << "    b: " << b << "  position: " << team[b].x << team[b].y << endl;
    if(left>right){
        team[b].probability = left;
        team[b].leftVright = 0;
    }
    if(right>left){
        team[b].probability = right;
        team[b].leftVright = 1;
    }
    if(left==right){
        /* initialize random seed: */
        srand (time(NULL));
        /* generate secret number between 1 and 2: */
        int randNum = rand() % 3;
        if(randNum%2==0){
            team[b].probability = left;
            team[b].leftVright = 0;
        }
        else
        {
            team[b].probability = right;
            team[b].leftVright = 1;
        }
        }
}

void AI::moveChoose(){
    cout<<"AI's Turn"<<endl;
    for(int b=0;b<12;b++){
        moveCheck(team[b].x, team[b].y, b);
    }
    int temp = 0;
    int bestPice = 0;
    for(int b=0;b<team.size();b++){
        if(team[b].probability>temp) {
            cout<< "new neo: " << team[b].x << team[b].y << "    b: " << b << endl;
            temp = team[b].probability;
            bestPice = b;
        }
    }
    if(team[bestPice].leftVright == 0){
        cout<< "the chosen one: " << team[bestPice].x << "," << team[bestPice].y << "best move: " << team[bestPice].x-1 << "," << team[bestPice].y+1 << endl;
        movePiece(team[bestPice].x, team[bestPice].y, team[bestPice].x -1, team[bestPice].y +1);
    }
    else{
        cout<< "the chosen one: " << team[bestPice].x << "," << team[bestPice].y << "best move: " << team[bestPice].x+1 << "," << team[bestPice].y+1 << endl;
        movePiece(team[bestPice].x, team[bestPice].y, team[bestPice].x +1, team[bestPice].y +1);
    }
}
