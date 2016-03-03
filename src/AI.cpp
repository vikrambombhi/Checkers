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
                break;
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

int AI::threatCheckBackLeft(int x, int y){
    if(x>0 && y<7){
        if(Board->virtualBoard[x-1][y-1] == RED_PIECE){
            return RED_PIECE;
        }
        if(Board->virtualBoard[x-1][y-1] == BLACK_PIECE){
            return BLACK_PIECE;
        }
        if(Board->virtualBoard[x-1][y-1] == EMPTY_PIECE){
            return EMPTY_PIECE;
        }
    }
    return -1;
}

bool AI::killCheckLeft(int x, int y){
    if(x>1 && y<6){
        if(Board->virtualBoard[x-1][y+1] == EMPTY_PIECE){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
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

int AI::threatCheckBackRight(int x, int y){
    if(x<7 && y <7){
        if(Board->virtualBoard[x+1][y-1] == RED_PIECE){
            return RED_PIECE;
        }
        if(Board->virtualBoard[x+1][y-1] == BLACK_PIECE){
            return BLACK_PIECE;
        }
        if(Board->virtualBoard[x+1][y-1] == EMPTY_PIECE){
            return EMPTY_PIECE;
        }
    }
    return -1;
}

bool AI::killCheckRight(int x, int y){
    if(x<6 && y<6){
        if(Board->virtualBoard[x+1][y+1] == EMPTY_PIECE){
            return true;
        }
        else{
            return false;
        }
    }
    return false;
}

int AI:: checkLeft(int x, int y, int left){
    if(x<1 || y>8){
        return -999999999;
    }

    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        left += 25;

        //Check if board exits to left
        if(threatCheckLeft(x, y) == -1){
            return left;
        }
        // Check if move will kill me
        else if(threatCheckLeft(x, y) == RED_PIECE && threatCheckBackRight(x, y) == EMPTY_PIECE){
            left = left-75;
        }

        //Check if board exists to right
        if(threatCheckRight(x, y) == -1){
            return left;
        }
        else if(threatCheckRight(x, y) == RED_PIECE && threatCheckBackLeft(x, y) == EMPTY_PIECE){
            left = left-75;
        }
    }

    if(Board->virtualBoard[x][y] == RED_PIECE){
        //Check if I can kill to left
        if(killCheckLeft(x, y) == true){
            left = left+150;
            cout<<"TEST"<<endl;
        }
        if(killCheckLeft(x,y) == false){
            cout<<"KILL ME"<<endl;
        }
    }

    if(Board->virtualBoard[x][y] == BLACK_PIECE){
        left -= 999999999;
    }
    return left;
}

int AI:: checkRight(int x, int y,int right){
    if(x>6 || y>8){
        return -999999999;
    }

    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        right += 25;

        //Check if board exits to left
        if(threatCheckLeft(x, y) == -1){
            return right;
        }
        // Check if move will kill me
        else if(threatCheckLeft(x, y) == RED_PIECE && threatCheckBackRight(x, y) == EMPTY_PIECE){
            right -= 75;
        }

        //Check if board exists to right
        if(threatCheckRight(x, y) == -1){
            return right;
        }
        else if(threatCheckRight(x, y) == RED_PIECE && threatCheckBackLeft(x, y) == EMPTY_PIECE){
            right -= 75;
        }
    }

    if(Board->virtualBoard[x][y] == RED_PIECE){
        //Check if I can kill to right
        if(killCheckRight(x, y) == true){
            right += 150;
        }
    }

    if(Board->virtualBoard[x][y] == BLACK_PIECE){
        right -= 999999999;
    }
    return right;
}

void AI::moveCheck(int b, int depth){
    if(depth == 0 || team[b].x>8 || team[b].y>8 || team[b].x<0 || team[b].y<0){
        exit(-1);
    }

    int left = checkLeft(team[b].x-1, team[b].y+1, 0);
    int right = checkRight(team[b].x+1, team[b].y+1, 0);

    cout<< "left: " << left << " " << "Right: " << right << "    b: " << b << "  position: " << team[b].x <<"," << team[b].y << endl;
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

void AI::makeMove(){
    cout<<"AI's Turn"<<endl;
    for(int b=0;b<12;b++){
        moveCheck(b, 10);
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
