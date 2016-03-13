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

int AI::extentValue(int y){
    if (topSide) {
        return y;
    }
    else{
        return 7-y;
    }
}

int AI::threatCheckArea(int x, int y, directions checkDirection){
        switch (checkDirection) {
            case LEFT:
                if(x<=0 || y>=7){
                    return -1;
                }
                x -= 1;
                y += ONE;
                break;
            case RIGHT:
                if(x>=7 || y>=7){
                    return -1;
                }
                x += 1;
                y += ONE;
                break;
            case BACK_LEFT:
                if(x<=0 || y<=0){
                    return -1;
                }
                x -= 1;
                y -= ONE;
                break;
            case BACK_RIGHT:
                if(x>=7 || y<=0){
                    return -1;
                }
                x += 1;
                y -= ONE;
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
        if(Board->virtualBoard[x-1][y+ONE] == EMPTY_PIECE){
            return true;
        }
    }
    return false;
}

bool AI::killCheckRight(int x, int y){
    if(x<7 && y<7){
        if(Board->virtualBoard[x+1][y+ONE] == EMPTY_PIECE){
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
        left += extentValue(y);
        //Check if board exits to left
        if(threatCheckArea(x, y, LEFT) != -1){

        // Check if move will kill me
            if(threatCheckArea(x, y, LEFT) == ENEMY_TEAM_NUMBER){
                left = left + extentValue(y) - KILL_PIECE;
            }
        }

        //Check if board exists to right
        if(threatCheckArea(x, y, RIGHT) != -1){
            if(threatCheckArea(x, y, RIGHT) == ENEMY_TEAM_NUMBER && threatCheckArea(x, y, BACK_LEFT) == EMPTY_PIECE){
                left = left + extentValue(y) - KILL_PIECE;
            }
        }
    }

    if(Board->virtualBoard[x][y] == ENEMY_TEAM_NUMBER){
        //Check if I can kill to left
        if(killCheckLeft(x, y) == true){
            left = left + extentValue(y) + KILL_PIECE;
        }
        else{
            left = OUT_OF_BOUND;
        }
    }

    if(Board->virtualBoard[x][y] == TEAM_NUMBER){
        left = OUT_OF_BOUND;
    }
    return left;
}

int AI:: checkRight(int x, int y,int right){
    if(x<0 || y<0 || y>7 || x>7){
        return OUT_OF_BOUND;
    }

    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        right += extentValue(y);
        //Check if board exits to left
        if(threatCheckArea(x, y, LEFT) != -1){

        // Check if move will kill me
            if(threatCheckArea(x, y, LEFT) == ENEMY_TEAM_NUMBER && threatCheckArea(x, y, BACK_RIGHT) == EMPTY_PIECE){
                right = right + extentValue(y) - KILL_PIECE;
            }
        }

        //Check if board exists to right
        if(threatCheckArea(x, y, RIGHT) != -1){
            if(threatCheckArea(x, y, RIGHT) == ENEMY_TEAM_NUMBER){
                right = right + extentValue(y) - KILL_PIECE;
            }
        }
    }

    if(Board->virtualBoard[x][y] == ENEMY_TEAM_NUMBER){
        //Check if I can kill to right
        if(killCheckRight(x, y) == true){
            right = right + extentValue(y) + KILL_PIECE;
        }
        else{
            right = OUT_OF_BOUND;
        }
    }

    if(Board->virtualBoard[x][y] == TEAM_NUMBER){
        right = OUT_OF_BOUND;
    }
    return right;
}

void AI::moveCheck(int index, int depth){
    if(depth == 0 || team[index].x>8 || team[index].y>8 || team[index].x<0 || team[index].y<0){
        exit(-1);
    }

    int left = checkLeft(team[index].x-1, team[index].y+ONE, 0);
    int right = checkRight(team[index].x+1, team[index].y+ONE, 0);

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
        srand(static_cast<unsigned int>(time(NULL)));
        /* generate secret number between 1 and 2: */
        int randNum = rand() % 3;
        if(randNum%2==0){
            team[index].probability = left;
            team[index].leftVright = 0;
        }
        else{
            team[index].probability = right;
            team[index].leftVright = 1;
        }
    }
}

bool AI::makeMove(SDL_Event *event){
    cout<<"AI's Turn"<<endl;
    for(int index=0;index<team.size();index++){
        moveCheck(index, 10);
    }
    int bestPieceIndex = 0;
    int temp = team[bestPieceIndex].probability;
    for(int teamIndex=0;teamIndex<team.size();teamIndex++){
        // If probability is the same, will stick with the first index
        if(team[teamIndex].probability>temp) {
            temp = team[teamIndex].probability;
            bestPieceIndex = teamIndex;
        }
    }
    // .5 second delay for the AI to start moving //
    // OR NAH //
    //SDL_Delay(500);
    
    cout<< "the chosen one: " << bestPieceIndex << " -> "<< team[bestPieceIndex].x << "," << team[bestPieceIndex].y;
    if(team[bestPieceIndex].leftVright == LEFT){
        if(Board->virtualBoard[team[bestPieceIndex].x-1][team[bestPieceIndex].y+ONE] == ENEMY_TEAM_NUMBER){
            cout<< " best move: " << team[bestPieceIndex].x-2 << "," << team[bestPieceIndex].y+2*ONE << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x-2, team[bestPieceIndex].y+2*ONE);
            return true;
        }
        if(Board->virtualBoard[team[bestPieceIndex].x-1][team[bestPieceIndex].y+ONE] == EMPTY_PIECE){
            cout<< " best move: " << team[bestPieceIndex].x-1 << "," << team[bestPieceIndex].y+ONE << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x-1, team[bestPieceIndex].y+ONE);
            return true;
        }
    }
    else{
        if(Board->virtualBoard[team[bestPieceIndex].x+1][team[bestPieceIndex].y+ONE] == ENEMY_TEAM_NUMBER){
            cout<< " best move: " << team[bestPieceIndex].x+2 << "," << team[bestPieceIndex].y+2*ONE << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x+2, team[bestPieceIndex].y+2*ONE);
            return true;
        }
        if(Board->virtualBoard[team[bestPieceIndex].x+1][team[bestPieceIndex].y+ONE] == EMPTY_PIECE){
            cout<< " best move: " << team[bestPieceIndex].x+1 << "," << team[bestPieceIndex].y+ONE << endl;
            movePiece(bestPieceIndex, team[bestPieceIndex].x+1, team[bestPieceIndex].y+ONE);
            return true;
        }
    }
    return false;
}
