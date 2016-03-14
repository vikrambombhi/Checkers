#include<iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "../include/AI.h"
#include "../include/GameState.h"

AI::AI(bool topSideOfBoard, CheckersBoard *board, Button *buttons): Player(topSideOfBoard, board, buttons){
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

int AI::threatCheckArea(int x, int y, Directions checkDirection){
        switch (checkDirection) {
            case LEFT:
                x -= 1;
                y += ONE;
                break;
            case RIGHT:
                x += 1;
                y += ONE;
                break;
            case BACK_LEFT:
                x -= 1;
                y -= ONE;
                break;
            case BACK_RIGHT:
                x += 1;
                y -= ONE;
                break;
            default:
                return -1;
                break;
        }
        if(x<0 || y<0 || y>7 || x>7){
            return -1;
        }
    return Board->virtualBoard[x][y];
}

bool AI::killCheckArea(int x, int y, Directions checkDirection){
    switch (checkDirection) {
        case LEFT:
            x -= 1;
            y += ONE;
            break;
        case RIGHT:
            x += 1;
            y += ONE;
            break;
        case BACK_LEFT:
            x -= 1;
            y -= ONE;
            break;
        case BACK_RIGHT:
            x += 1;
            y -= ONE;
            break;
        default:
            return false;
            break;
    }
    if(x<0 || y<0 || y>7 || x>7){
        return false;
    }
    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        return true;
    }
    return false;
}

int AI::checkArea(int x, int y, Directions checkDirection, int points){
    if(x<0 || y<0 || y>7 || x>7){
        return OUT_OF_BOUND;
    }

    switch (checkDirection) {
        case LEFT:
            if(Board->virtualBoard[x][y] == EMPTY_PIECE){
                points += extentValue(y);
                //Check if board exits to left
                if(threatCheckArea(x, y, LEFT) != -1){
                    // Check if move will kill me
                    if(threatCheckArea(x, y, LEFT) == ENEMY_TEAM_NUMBER){
                        points = points + extentValue(y) - KILL_PIECE;
                    }
                    //Check if move will block my team from killing me
                    if(threatCheckArea(x, y, LEFT) == TEAM_NUMBER && threatCheckArea(x-1, y+ONE, LEFT) == ENEMY_TEAM_NUMBER){
                        points = points + extentValue(y) + BLOCK;
                    }
                }

                //Check if board exists to right
                if(threatCheckArea(x, y, RIGHT) != -1){
                    //Check if move will kill me
                    if(threatCheckArea(x, y, RIGHT) == ENEMY_TEAM_NUMBER && threatCheckArea(x, y, BACK_LEFT) == EMPTY_PIECE){
                        points = points + extentValue(y) - KILL_PIECE;
                    }
                    //Check if move will block my team from killing me
                    if(threatCheckArea(x, y, RIGHT) == TEAM_NUMBER && threatCheckArea(x+1, y+ONE, RIGHT) == ENEMY_TEAM_NUMBER){
                        points = points + extentValue(y) + BLOCK;
                    }
                }
            }
            break;

        case RIGHT:
            if(Board->virtualBoard[x][y] == EMPTY_PIECE){
                points += extentValue(y);

                //Check if board exits to left
                if(threatCheckArea(x, y, LEFT) != -1){
                    // Check if move will kill me
                    cout<<"threatcheck back right:  "<<threatCheckArea(x,y,BACK_RIGHT)<<endl;
                    if(threatCheckArea(x, y, LEFT) == ENEMY_TEAM_NUMBER && threatCheckArea(x, y, BACK_RIGHT) == EMPTY_PIECE){
                        points = points + extentValue(y) - KILL_PIECE;
                    }
                    //Check if move will block my team from killing me
                    if(threatCheckArea(x, y, LEFT) == TEAM_NUMBER && threatCheckArea(x-1, y+ONE, LEFT) == ENEMY_TEAM_NUMBER){
                        points = points + extentValue(y) + BLOCK;
                    }
                }

                //Check if board exists to right
                if(threatCheckArea(x, y, RIGHT) != -1){
                    //Check if move will kill me
                    if(threatCheckArea(x, y, RIGHT) == ENEMY_TEAM_NUMBER){
                        points = points + extentValue(y) - KILL_PIECE;
                    }
                    //Check if move will block my team from killing me
                    if(threatCheckArea(x, y, RIGHT) == TEAM_NUMBER && threatCheckArea(x+1, y+ONE, RIGHT) == ENEMY_TEAM_NUMBER){
                        points = points + extentValue(y) + BLOCK;
                    }
                }
            }
            break;

        default:
            break;
    }

    if(Board->virtualBoard[x][y] == ENEMY_TEAM_NUMBER){
        //Check if I can kill to left
        if(killCheckArea(x, y, checkDirection) == true){
            points = points + extentValue(y) + KILL_PIECE;
        }
        else{
            points = OUT_OF_BOUND;
        }
    }
    if(Board->virtualBoard[x][y] == TEAM_NUMBER){
        points = OUT_OF_BOUND;
    }
    return points;
}

void AI::moveCheck(int index, int depth){
    if(depth == 0 || team[index].x>8 || team[index].y>8 || team[index].x<0 || team[index].y<0){
        exit(-1);
    }

    int left = 0;
    int right = 0;
    left = checkArea(team[index].x-1, team[index].y+ONE, LEFT, left);
    right = checkArea(team[index].x+1, team[index].y+ONE, RIGHT, right);

    cout<< "index: " << index<< " left: " << left << " " << "Right: " << right  << "  position: " << team[index].x <<"," << team[index].y << endl;
    if(left>right){
        team[index].probability = left;
        team[index].bestDirection = LEFT;
    }
    if(right>left){
        team[index].probability = right;
        team[index].bestDirection = RIGHT;
    }
    if(left==right){
        /* initialize random seed: */
        srand(static_cast<unsigned int>(time(NULL)));
        /* generate secret number between 1 and 2: */
        int randNum = rand() % 3;
        if(randNum%2==0){
            team[index].probability = left;
            team[index].bestDirection = LEFT;
        }
        else{
            team[index].probability = right;
            team[index].bestDirection = RIGHT;
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
    if(team[bestPieceIndex].bestDirection == LEFT){
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
