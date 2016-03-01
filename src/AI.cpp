#include<iostream>
#include <cstdlib>
#include "../include/AI.h"

AI::AI(bool topSide, CheckersBoard *board, Button *buttons): Player(topSide, board, buttons){
}

AI::~AI(){
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

struct tempPos{
 int x;
 int y;
}bestMove;

int AI::updateProb(int x, int y, int val, int b)
{
    if((y>7) || (x>7)|| (y<0) || (x<0)){
        cout << "in loop" << team[b].x << "," << team[b].y << endl;
        cout << x << "," << y << "," << val << "," << "," << b << endl;
        if(x>=8){
            x = x - 1;
        }
        if(y>=8){
            y = y - 1;
        }
        bestMove.x = x;
        bestMove.y = y;
        cout << "val: " << val << endl;
        return val;
    }
    else
    {
        if(Board->virtualBoard[x][y] == 2){
            cout << "if caught 1" << endl;
            updateProb(x + 1, y + 1, val, b);
            updateProb(x - 1, y + 1, val, b);
            cout << "if exit 1" << endl;
        }
        if(Board->virtualBoard[x][y] == 1){
            cout << "if caught 2" << endl;
            updateProb(x + 1, y + 1, val + 1, b);
            updateProb(x - 1, y + 1, val + 1, b);
            cout << "if exit 2" << endl;
        }
        if(Board->virtualBoard[x][y] == 0){
            cout << "if caught 3.1" << endl;
            if(x>=7){
                if(Board->virtualBoard[x-1][y+1] == 1){
                    cout << "if caught 3.3" << endl;
                    updateProb(x - 1, y + 1, val + 1, b);
                }
                if(Board->virtualBoard[x-1][y+1] == 0){
                    cout << "if caught 3.5" << endl;
                    updateProb(x - 1, y + 1, val + 1, b);
                }
            }
            if(y>=8){
                //lel jest dont do anything
            }
            if(x<0){
                if(Board->virtualBoard[x+1][y+1] == 1){
                    cout << "if caught 3.2" << endl;
                    updateProb(x + 1, y + 1, val + 1, b);
                }
                if(Board->virtualBoard[x+1][y+1] == 0){
                    cout << "if caught 3.4" << endl;
                    updateProb(x + 1, y + 1, val + 1, b);
                }
            }
            if(y<0){
                if(Board->virtualBoard[x+1][y+1] == 1){
                    cout << "if caught 3.2" << endl;
                    updateProb(x + 1, y + 1, val + 1, b);
                }
                if(Board->virtualBoard[x-1][y+1] == 1){
                    cout << "if caught 3.3" << endl;
                    updateProb(x - 1, y + 1, val + 1, b);
                }
                if(Board->virtualBoard[x+1][y+1] == 0){
                    cout << "if caught 3.4" << endl;
                    updateProb(x + 1, y + 1, val + 1, b);
                }
                if(Board->virtualBoard[x-1][y+1] == 0){
                    cout << "if caught 3.5" << endl;
                    updateProb(x - 1, y + 1, val + 1, b);
                }
            }
            cout << "if exit 3" << endl;
        }
    }
    return EXIT_FAILURE;
}

void AI::movePiece(int neo_x, int neo_y){
    // LOLZ PLZ WORK//
    if((Board->virtualBoard[neo_x][neo_y] == 2) && (Board->virtualBoard[bestMove.x][bestMove.y] == 0)){
        Board->virtualBoard[bestMove.x][bestMove.y] = 2;
        Board->virtualBoard[neo_x][neo_y] = 0;
    }
    for(int b=0;b<TEAM_SIZE;b++){
            if((team[b].x == neo_x) && (team[b].y == neo_y)){
                team[b].x = bestMove.x;
                team[b].y = bestMove.y;
               }
        }
    Board->printBoard();
}

void AI::moveChoose(){
    cout<<"AI's Turn"<<endl;
    for(int b=0;b<12;b++){
        team[b].probability = updateProb(team[b].x, team[b].y, 0, b);
    }
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
}
