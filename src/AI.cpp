#include<iostream>
#include "../include/AI.h"

AI::AI(bool topSide): Player(topSide){
}

struct tempPos{
 int x;
 int y;
}bestMove;

int AI::updateProb(int x, int y, int val, int times)
{
    if(times<1)
    {
        if((y>8) || (x>8)){
            bestMove.x = x;
            bestMove.y = y;
            return val+10;
        }
        if(Board.virtualBoard[x][y] == 2){
            updateProb(x + 1, y + 1, val, times + 1);
            updateProb(x - 1, y + 1, val, times + 1);
        }
        if(Board.virtualBoard[x][y] == 1){
            updateProb(x + 1, y + 1, val + 1,times + 1);
            updateProb(x - 1, y + 1, val + 1,times + 1);
        }
        if(Board.virtualBoard[x][y] == 0){
            if(Board.virtualBoard[x+1][y+1] == 1){
                updateProb(x + 1, y + 1, val + 1,times + 1);
            }
            if(Board.virtualBoard[x-1][y+1] == 1){
                updateProb(x - 1, y + 1, val + 1,times + 1);
            }
            if(Board.virtualBoard[x+1][y+1] == 0){
                updateProb(x + 1, y + 1, val + 1,times + 1);
            }
            if(Board.virtualBoard[x-1][y+1] == 0){
                updateProb(x - 1, y + 1, val + 1,times + 1);
            }
        }
    }
    else{
        bestMove.x = x;
        bestMove.y = y;
        cout << "val: " << val << endl;
        return val;
    }
}

void AI::movePiece(int neo_x, int neo_y){
    // LOLZ PLZ WORK//
    if((Board.virtualBoard[neo_x][neo_y] == 2) && (Board.virtualBoard[bestMove.x][bestMove.y] == 0)){
        Board.virtualBoard[bestMove.x][bestMove.y] = 2;
        Board.virtualBoard[neo_x][neo_y] = 0;
    }
    for(int b=0;b<12;b++){
            if((team[b].x == neo_x) && (team[b].y == neo_y)){
                team[b].x = bestMove.x;
                team[b].y = bestMove.y;
               }
        }
    Board.printBoard();
}

void AI::moveChoose(){
    cout<<"AI's Turn"<<endl;
    for(int b=9;b<10;b++){
        team[b].probability = updateProb(team[b].x, team[b].y, 0, 0);
    }

    int temp = 0;
    int neo_x;
    int neo_y;
    for(int b=0;b<12;b++){
        if(team[b].probability>temp) {
            temp = team[b].probability;
            neo_x = team[b].x;
            neo_y = team[b].y;
        }
    }
    cout<< "the chosen one" << neo_x << "," << neo_y << "best move" << bestMove.x << "," << bestMove.y << endl;
    movePiece(neo_x, neo_y);
}
