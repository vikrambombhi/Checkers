#include<iostream>
#include "../include/AI.h"

AI::AI(bool topSide): Player(topSide){
}

int AI::updateProb(int x, int y, int val)
{
    if((x>8)){
        return val+10;
    }
    if(Board.virtualBoard[x][y] == 2){
        updateProb(x + 1, y + 1, val);
        updateProb(x - 1, y + 1, val);
    }
    if(Board.virtualBoard[x][y] == 1){
        updateProb(x + 1, y + 1, val + 1);
        updateProb(x - 1, y + 1, val + 1);
    }
    if(Board.virtualBoard[x][y] == 0){
        if(Board.virtualBoard[x+1][y+1] == 1){
            updateProb(x + 1, y + 1, val + 1);
        }
        if(Board.virtualBoard[x-1][y+1] == 1){
            updateProb(x - 1, y + 1, val + 1);
        }
    }
    return val;
}

void AI::moveChoose(){
    for(int b=0;b<4;b++){
        team[b].probability = updateProb(team[b].x, team[b].y, 0);
    }

    int temp = 0;
    int neo_x;
    int neo_y;
    for(int b=0;b<4;b++){
        if(team[b].probability>temp) {
            temp = team[b].probability;
            neo_x = team[b].x;
            neo_y = team[b].y;
        }
    }
}
