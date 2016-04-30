#include<iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "../include/AI.h"
#include "../include/GameState.h"

AI::AI(bool topSideOfBoard, CheckersBoard *board, Button *buttons): Player(topSideOfBoard, board, buttons){
    currentIndex = 0;
}

AI::~AI(){
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

int AI::returnRandomIndex(vector<int> bestPiecesList){
    /* initialize random seed: */
    srand(static_cast<unsigned int>(time(NULL)));
    /* generate secret number from 0 to vectorSize*/
    int randPiece = rand() % bestPiecesList.size();
    return bestPiecesList[randPiece];

}

bool AI::changeWithDirection(int *x, int *y, Directions direction){
    switch (direction) {
        case LEFT:
            *x -= 1;
            *y += ONE;
            break;
        case RIGHT:
            *x += 1;
            *y += ONE;
            break;
        case BACK_LEFT:
            *x -= 1;
            *y -= ONE;
            break;
        case BACK_RIGHT:
            *x += 1;
            *y -= ONE;
            break;
        default:
            return false;
            break;
    }
    return true;
}

int AI::threatCheckArea(int x, int y, Directions checkDirection){
    // Makes sure direction was able to be changed//
    if(!changeWithDirection(&x, &y, checkDirection)){
        return -1;
    }
    // Makes sure new values are in bound //
    if(x<0 || y<0 || y>7 || x>7){
        return -1;
    }
    // Returns value in direction //
    return Board->virtualBoard[x][y];
}

bool AI::killCheckArea(int x, int y, Directions checkDirection){
    // Makes sure direction was able to be changed//
    if(!changeWithDirection(&x, &y, checkDirection)){
        return false;
    }
    // Makes sure new values are in bound //
    if(x<0 || y<0 || y>7 || x>7){
        return false;
    }
    // Returns true if direction is clear //
    if(Board->virtualBoard[x][y] == EMPTY_PIECE){
        return true;
    }
    return false;
}

bool AI::checkNode(int index, Directions direction){
    int x = team[index].x;
    int y = team[index].y;
    if(!changeWithDirection(&x , &y, direction)){
        return false;
    };
    // Makes sure new values are in bound //
    if(x<0 || y<0 || y>7 || x>7){
        return false;
    }
    if(sameTeam(Board->virtualBoard[x][y], TEAM_NUMBER){
        return false;
    }
    if(sameTeam(Board->virtualBoard[x][y], ENEMY_TEAM_NUMBER)){
        return killCheckArea(x, y, direction);
    }
    return true;
}

void AI::getEnemyTeam(){
    enemyTeam.clear();
    for(int x=0;x<8;x++){
        for(int y=0;y<8;y++){
            if (sameTeam(Board->virtualBoard[x][y],ENEMY_TEAM_NUMBER)) {
                enemyTeam.push_back(Piece());
                if (Board->virtualBoard[x][y] == ENEMY_TEAM_NUMBER+2){
                    enemyTeam.back().makeKing();
                }
                enemyTeam.back().x = x;
                enemyTeam.back().y = y;
            }
        }
    }
}

int findMax(int value1, int value2){
    if (value1 > value2) {
        return value1;
    }
    return value2;
}

int findMin(int value1, int value2){
    if (value1 < value2) {
        return value1;
    }
    return value2;
}

int maxValue(CheckersBoard tempBoard, int depth, Directions direction, int value){
    if(depth < 0){
        return value;
    }
    if(!checkNode()){
        return OUT_OF_BOUND;
    }

    //make the move on temp board
    changeWithDirection(&x, &y, direction);
    if(sameTeam(Board->virtualBoard[x][y],ENEMY_TEAM_NUMBER)){
        // Changes it again for moving 2 units diagonally //
        changeWithDirection(&x, &y, direction);
    }
    //This should move on the tempBoard
    movePiece(bestPieceIndex, x, y);

    getEnemyTeam();

    value = team.size() - enemyTeam.size();
    // check for every direction in vector
    if(team[currentIndex].isKing){
        for(int d = 0; d<4; d++){
            value = findMax(value, minValue(tempBoard, depth--, kingMoves[d], value));
        }
    }
    else{
       for(int d = 0; d<2; d++){
            value = findMax(value, minValue(tempBoard, depth--, pieceMoves[d], value));
        }
    }
    return value;
}

int minValue(CheckersBoard tempBoard, int depth, Directions direction, int value){

    return 0;
}

bool AI::makeMove(SDL_Event *event){
    for(int index=0;index<team.size();index++){
        currentIndex = index;
        //team[currentIndex].potenial = maxValue();
    }

    vector<int> bestPiecesList;
    double largestPotential = team[0].potential;

    for(int teamIndex=0;teamIndex<team.size();teamIndex++){
        // If potential is the same, will stick with the first index
        if(team[teamIndex].potential > largestPotential) {
            largestPotential = team[teamIndex].potential;
        }
    }

    for(int teamIndex=0;teamIndex<team.size();teamIndex++){
        if(team[teamIndex].potential >= largestPotential){
            bestPiecesList.push_back(teamIndex);
        }
    }
    int bestPieceIndex = returnRandomIndex(bestPiecesList);
    cout<< "the chosen one: " << bestPieceIndex << " -> "<< team[bestPieceIndex].x << "," << team[bestPieceIndex].y;

    int x = team[bestPieceIndex].x;
    int y = team[bestPieceIndex].y;

    // Makes sure the move isnt out of bounds //
    if (team[bestPieceIndex].potential != OUT_OF_BOUND) {

        switch (team[bestPieceIndex].bestDirection) {
            case LEFT:
                changeWithDirection(&x, &y, LEFT);
                if(sameTeam(Board->virtualBoard[x][y],ENEMY_TEAM_NUMBER)){
                    // Changes it again for moving 2 units diagonally //
                    changeWithDirection(&x, &y, LEFT);
                }
                cout<< " best move: " << x << "," << y << endl;
                movePiece(bestPieceIndex, x, y);
                return true;

            case RIGHT:
                changeWithDirection(&x, &y, RIGHT);
                if (sameTeam(Board->virtualBoard[x][y], ENEMY_TEAM_NUMBER)) {
                    // Changes it again for moving 2 units diagonally //
                    changeWithDirection(&x, &y, RIGHT);
                }
                cout<< " best move: " << x << "," << y << endl;
                movePiece(bestPieceIndex, x, y);
                return true;

            case BACK_LEFT:
                changeWithDirection(&x, &y, BACK_LEFT);
                if (sameTeam(Board->virtualBoard[x][y], ENEMY_TEAM_NUMBER)) {
                    // Changes it again for moving 2 units diagonally //
                    changeWithDirection(&x, &y, BACK_LEFT);
                }
                cout<< " best move: " << x << "," << y << endl;
                movePiece(bestPieceIndex, x, y);
                return true;

            case BACK_RIGHT:
                changeWithDirection(&x, &y, BACK_RIGHT);
                if (sameTeam(Board->virtualBoard[x][y], ENEMY_TEAM_NUMBER)) {
                    // Changes it again for moving 2 units diagonally //
                    changeWithDirection(&x, &y, BACK_RIGHT);
                }
                cout<< " best move: " << x << "," << y << endl;
                movePiece(bestPieceIndex, x, y);
                return true;

            default:
                break;
        }
    }
    return false;
}
