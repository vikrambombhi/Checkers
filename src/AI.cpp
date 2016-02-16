#include <iostream>
#include <vector>
#include "../include/CheckersBoard.h"

using namespace std;

int choose(int x, int y, int val){
    if((x>8)){
        return val+10;
    }
    if(Board.virtualBoard[x][y] == 2){
        choose(x + 1, y + 1, val);
        choose(x - 1, y + 1, val);
    }
    if(Board.virtualBoard[x][y] == 1){
        choose(x + 1, y + 1, val + 1);
        choose(x - 1, y + 1, val + 1);
    }
    if(Board.virtualBoard[x][y] == 0){
        if(Board.virtualBoard[x+1][y+1] == 1){
            choose(x + 1, y + 1, val + 1);
        }
        if(Board.virtualBoard[x-1][y+1] == 1){
            choose(x - 1, y + 1, val + 1);
        }
    }
    return val;
}

void theChoosenOne(){
    for(int b=0;b<4;b++){
        blackTeam[b].prob = choose(blackTeam[b].x, blackTeam[b].y, 0);
    }

    int temp = 0;
    int neo_x;
    int neo_y;
    for(int b=0;b<4;b++){
        if(blackTeam[b].prob>temp) {
            temp = blackTeam[b].prob;
            neo_x = blackTeam[b].x;
            neo_y = blackTeam[b].y;
        }
    }
}