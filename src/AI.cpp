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

int AI::threatCheckArea(int x, int y, directions checkDirection){
        switch (checkDirection) {
            case LEFT:
                if(x>=0 && y<=7){
                    return -1;
                }
                x -= 1;
                y += 1;
                break;
            case RIGHT:
                if(x<=7 && y <=7){
                    return -1;
                }
                x += 1;
                y += 1;
                break;
            case BACK_LEFT:
                if(x>=0 && y>=0){
                    return -1;
                }
                x -= 1;
                y -= 1;
                break;
            case BACK_RIGHT:
                if(x<=7 && y>=0){
                    return -1;
                }
                x += 1;
                y -= 1;
            default:
                return -1;
                break;
        }
        if(Board->virtualBoard[x][y] == RED_PIECE){
            return RED_PIECE;
        }
        if(Board->virtualBoard[x][y] == BLACK_PIECE){
            return BLACK_PIECE;
        }
        if(Board->virtualBoard[x][y] == EMPTY_PIECE){
            return EMPTY_PIECE;
        }
    return -1;
}

bool AI::killCheckLeft(int x, int y){
    if(x>0 && y<7){
        if(Board->virtualBoard[x-1][y+1] == EMPTY_PIECE){
            return true;
        }
    }
    return false;
}

bool AI::killCheckRight(int x, int y){
    if(x<7 && y<7){
        if(Board->virtualBoard[x+1][y+1] == EMPTY_PIECE){
            return true;
        }
    }
    return false;
}

int AI:: checkLeft(int x, int y, int left){
    if(x<0 || y<0 || y>7 || x>7){
        return OUT_OF_BOUND;
    }

    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        left += y;

        //Check if board exits to left
        if(threatCheckArea(x, y, LEFT) == -1){
            return left;
        }
        // Check if move will kill me
        else if(threatCheckArea(x, y, LEFT) == RED_PIECE && threatCheckArea(x, y, BACK_RIGHT) == EMPTY_PIECE){
            left = left + y - KILL_PIECE;
        }

        //Check if board exists to right
        if(threatCheckArea(x, y, RIGHT) == -1){
            return left;
        }
        else if(threatCheckArea(x, y, RIGHT) == RED_PIECE && threatCheckArea(x, y, BACK_LEFT) == EMPTY_PIECE){
            left = left + y - KILL_PIECE;
        }
    }

    if(Board->virtualBoard[x][y] == RED_PIECE){
        //Check if I can kill to left
        if(killCheckLeft(x, y) == true){
            left = left + y + KILL_PIECE;
        }
    }

    if(Board->virtualBoard[x][y] == BLACK_PIECE){
        left += OUT_OF_BOUND;
    }
    return left;
}

int AI:: checkRight(int x, int y,int right){
    if(x<0 || y<0 || y>7 || x>7){
        return OUT_OF_BOUND;
    }

    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        right += y;

        //Check if board exits to left
        if(threatCheckArea(x, y, LEFT) == -1){
            return right;
        }
        // Check if move will kill me
        else if(threatCheckArea(x, y, LEFT) == RED_PIECE && threatCheckArea(x, y, BACK_RIGHT) == EMPTY_PIECE){
            right = right + y - KILL_PIECE;
        }

        //Check if board exists to right
        if(threatCheckArea(x, y, RIGHT) == -1){
            return right;
        }
        else if(threatCheckArea(x, y, RIGHT) == RED_PIECE && threatCheckArea(x, y, BACK_LEFT) == EMPTY_PIECE){
            right = right + y - KILL_PIECE;
        }
    }

    if(Board->virtualBoard[x][y] == RED_PIECE){
        //Check if I can kill to right
        if(killCheckRight(x, y) == true){
            right = right + y + KILL_PIECE;
        }
    }

    if(Board->virtualBoard[x][y] == BLACK_PIECE){
        right += OUT_OF_BOUND;
    }
    return right;
}

void AI::moveCheck(int index, int depth){
    if(depth == 0 || team[index].x>8 || team[index].y>8 || team[index].x<0 || team[index].y<0){
        exit(-1);
    }

    int left = checkLeft(team[index].x-1, team[index].y+1, 0);
    int right = checkRight(team[index].x+1, team[index].y+1, 0);

    cout<< "index: " << index<< " left: " << left << " " << "Right: " << right  << "  position: " << team[index].x <<"," << team[index].y << endl;
    if(left>right){
        team[index].probability = left;
        team[index].leftVright = 0;
    }
    if(right>left){
        team[index].probability = right;
        team[index].leftVright = 1;
    }
    if(left==right){
        /* initialize random seed: */
        srand (time(NULL));
        /* generate secret number between 1 and 2: */
        int randNum = rand() % 3;
        if(randNum%2==0){
            team[index].probability = left;
            team[index].leftVright = 0;
        }
        else
        {
          team[index].probability = right;
            team[index].leftVright = 1;
        }
        }
}

bool AI::makeMove(SDL_Event *event){
    cout<<"AI's Turn"<<endl;
    for(int b=0;b<team.size();b++){
        moveCheck(b, 10);
    }
    int temp = 0;
    int bestPieceIndex = 0;
    for(int teamIndex=0;teamIndex<team.size();teamIndex++){
        // If probability is the same, will stick with the first index
        if(team[teamIndex].probability>temp) {
            //cout<< "new neo: " << team[b].x << team[b].y << "    b: " << b << endl;
            temp = team[teamIndex].probability;
            bestPieceIndex = teamIndex;
        }
    }
    cout<< "the chosen one: " << bestPieceIndex << " -> "<< team[bestPieceIndex].x << "," << team[bestPieceIndex].y;
    if(team[bestPieceIndex].leftVright == 0){
        if(Board->virtualBoard[team[bestPieceIndex].x-1][team[bestPieceIndex].y+1] == RED_PIECE){

            cout<< " best move: " << team[bestPieceIndex].x-2 << "," << team[bestPieceIndex].y+2 << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x-2, team[bestPieceIndex].y+2);
            return true;
        }
        if(Board->virtualBoard[team[bestPieceIndex].x-1][team[bestPieceIndex].y+1] == EMPTY_PIECE){

            cout<< " best move: " << team[bestPieceIndex].x-1 << "," << team[bestPieceIndex].y+1 << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x-1, team[bestPieceIndex].y+1);
            return true;
        }
    }
    else{
        if(Board->virtualBoard[team[bestPieceIndex].x+1][team[bestPieceIndex].y+1] == RED_PIECE){

            cout<< " best move: " << team[bestPieceIndex].x+2 << "," << team[bestPieceIndex].y+2 << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x+2, team[bestPieceIndex].y+2);
            return true;
        }
        if(Board->virtualBoard[team[bestPieceIndex].x+1][team[bestPieceIndex].y+1] == EMPTY_PIECE){

            cout<< " best move: " << team[bestPieceIndex].x+1 << "," << team[bestPieceIndex].y+1 << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x+1, team[bestPieceIndex].y+1);
            return true;
        }
    }
    return false;
}
