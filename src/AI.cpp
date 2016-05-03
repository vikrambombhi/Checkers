#include<iostream>
#include "../include/AI.h"
#include "../include/GameState.h"

extern Directions kingMoves[4];
extern Directions pieceMoves[2];


AI::AI(bool topSideOfBoard, CheckersBoard *board, Button *buttons): Player(topSideOfBoard, board, buttons){
    currentIndex = 0;
}

AI::~AI(){
    delete Board;
    Board = NULL;
    delete boardButtons;
    boardButtons = NULL;
}

int AI::bestPiece(vector<Piece> pieceVector){
    
    int largest = pieceVector[0].potential;
    vector<int> largestVector;
    
    for(int i=0;i<pieceVector.size();i++){
        if(largest < pieceVector[i].potential) {
            largest = pieceVector[i].potential;
        }
    }
    
    for(int j=0;j<pieceVector.size();j++){
        if(largest <=pieceVector[j].potential){
            largestVector.push_back(j);
        }
    }
    
    /* initialize random seed: */
    srand(static_cast<unsigned int>(time(NULL)));
    /* generate secret number from 0 to vectorSize*/
    
    int randIndex = rand() % largestVector.size();
    return largestVector[randIndex];
}

bool AI::changeWithDirection(int *x, int *y, Directions direction, bool enemy){
    int one = ONE;
    
    if (enemy) {
        one = ONE * -1;
    }
    
    switch (direction) {
        case LEFT:
            *x -= 1;
            *y += one;
            break;
        case RIGHT:
            *x += 1;
            *y += one;
            break;
        case BACK_LEFT:
            *x -= 1;
            *y -= one;
            break;
        case BACK_RIGHT:
            *x += 1;
            *y -= one;
            break;
        default:
            return false;
            break;
    }
    return true;
}

bool AI::killCheckArea(int x, int y, Directions checkDirection, bool enemy){
    // Makes sure direction was able to be changed//
    if(!changeWithDirection(&x, &y, checkDirection, enemy)){
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

int AI::findMax(int value1, int value2){
    if (value1 > value2) {
        return value1;
    }
    return value2;
}

int AI::findMin(int value1, int value2){
    if (value1 < value2) {
        return value1;
    }
    return value2;
}

int AI::valueCalculator(){
    // TODO: ADD POINT SYSTEM FOR GOOD BOARD POSITIONS
    
    int value = 0;
    
    for(int i=0; i<team.size(); i++){
        if (team[i].isKing()) {
            value += 2;
        }
        else{
            value +=1;
        }
    }
    
    for(int j=0; j<enemyTeam.size(); j++){
        if (enemyTeam[j].isKing()) {
            value -= 2;
        }
        else{
            value -= 1;
        }
    }
    
    return value;
}

bool AI::checkNode(Directions direction, bool enemy){
    int x, y;
    int teamNumber = TEAM_NUMBER;
    int enemyTeamNumber = ENEMY_TEAM_NUMBER;
    
    if (enemy) {
        x = enemyTeam[enemyCurrentIndex].x;
        y = enemyTeam[enemyCurrentIndex].y;
        teamNumber = ENEMY_TEAM_NUMBER;
        enemyTeamNumber = TEAM_NUMBER;
    }
    else{
        x = team[currentIndex].x;
        y = team[currentIndex].y;
    }
    
    // Makes sure the changed x & y values are applied (Just incase)
    if(!changeWithDirection(&x , &y, direction, enemy)){
        return false;
    };
    
    // Makes sure new values are in bound //
    if(x<0 || y<0 || y>7 || x>7){
        return false;
    }
    
    // Team piece in the way
    if(sameTeam(Board->virtualBoard[x][y], teamNumber)){
        return false;
    }
    
    // Enemy might be unkillable
    if(sameTeam(Board->virtualBoard[x][y], enemyTeamNumber)){
        return killCheckArea(x, y, direction, enemy);
    }

    return true;
}

int AI::maxValue(CheckersBoard tempBoard, int depth, Directions direction, int value){
    if(depth < 0){
        return value;
    }
    if(!checkNode(direction, false)){
        return OUT_OF_BOUND;
    }
    int x = team[currentIndex].x;
    int y = team[currentIndex].y;
    
    //TODO: TEAM IS CONSTANTLY CHANGING, THE ACTUALLY STATE OF TEAM IS LOST, RESET SOMEWHERE
    
    //make the move on temp board
    changeWithDirection(&x, &y, direction, false);
    if(sameTeam(Board->virtualBoard[x][y],ENEMY_TEAM_NUMBER)){
        // Changes it again for moving 2 units diagonally //
        changeWithDirection(&x, &y, direction, false);
    }
    //This should move on the tempBoard
    movePiece(&tempBoard, team, currentIndex, x, y);
    
    value = valueCalculator();
    
    // check for every direction in vector
    if(team[currentIndex].isKing()){
        for(int d = 0; d<4; d++){
            value = findMax(value, minMove(tempBoard, depth--, kingMoves[d], value));
        }
    }
    else{
       for(int d = 0; d<2; d++){
            value = findMax(value, minMove(tempBoard, depth--, pieceMoves[d], value));
        }
    }
    return value;
}

int AI::minMove(CheckersBoard tempboard, int depth, Directions direction, int value){
    for(int index=0;index<enemyTeam.size();index++){
        enemyCurrentIndex = index;
        
        enemyTeam[index].directionValues[0] = minValue(tempboard, depth, LEFT, value);
        enemyTeam[index].directionValues[1] = minValue(tempboard, depth, RIGHT, value);
        
        if (team[index].isKing()) {
            enemyTeam[index].directionValues[2] = minValue(tempboard, depth, BACK_LEFT, value);
            enemyTeam[index].directionValues[3] = minValue(tempboard, depth, BACK_RIGHT, value);
        }
        
        enemyTeam[index].findBestDirection();
        
    }
    int bestPieceIndex = bestPiece(team);
    return enemyTeam[bestPieceIndex].potential;
}

int AI::minValue(CheckersBoard tempBoard, int depth, Directions direction, int value){

    if(depth < 0){
        return value;
    }
    if(!checkNode(direction, true)){
        return OUT_OF_BOUND;
    }
    
    int x = enemyTeam[enemyCurrentIndex].x;
    int y = enemyTeam[enemyCurrentIndex].y;
    
    //make the move on temp board
    changeWithDirection(&x, &y, direction, true);
    if(sameTeam(Board->virtualBoard[x][y],TEAM_NUMBER)){
        // Changes it again for moving 2 units diagonally //
        changeWithDirection(&x, &y, direction, true);
    }
    
    //This should move on the tempBoard
    movePiece(&tempBoard, enemyTeam, enemyCurrentIndex, x, y);
    
    value = valueCalculator();
    
    // check for every direction in vector
    if(enemyTeam[enemyCurrentIndex].isKing()){
        for(int d = 0; d<4; d++){
            value = findMin(value, maxValue(tempBoard, depth--, kingMoves[d], value));
        }
    }
    else{
        for(int d = 0; d<2; d++){
            value = findMin(value, maxValue(tempBoard, depth--, pieceMoves[d], value));
        }
    }
    return value;

}

bool AI::makeMove(SDL_Event *event){
    
    // Init enemyTeam that this class can use
    getEnemyTeam();

    for(int index=0;index<team.size();index++){
        currentIndex = index;

        team[index].directionValues[0] = maxValue(*Board, MAX_DEPTH, LEFT, OUT_OF_BOUND);
        team[index].directionValues[1] = maxValue(*Board, MAX_DEPTH, RIGHT, OUT_OF_BOUND);
        
        if (team[index].isKing()) {
            team[index].directionValues[2] = maxValue(*Board, MAX_DEPTH, BACK_LEFT, OUT_OF_BOUND);
            team[index].directionValues[3] = maxValue(*Board, MAX_DEPTH, BACK_RIGHT, OUT_OF_BOUND);
        }
        
        team[index].findBestDirection();

    }

    int bestPieceIndex = bestPiece(team);
    cout<< "The chosen one: " << bestPieceIndex << " -> "<< team[bestPieceIndex].x << "," << team[bestPieceIndex].y;

    int x = team[bestPieceIndex].x;
    int y = team[bestPieceIndex].y;

    // Makes sure the move isnt out of bounds //
    if (team[bestPieceIndex].potential != OUT_OF_BOUND) {
        
        changeWithDirection(&x, &y, team[bestPieceIndex].bestDirection, false);
        
        if(sameTeam(Board->virtualBoard[x][y],ENEMY_TEAM_NUMBER)){
            // Changes it again for moving 2 units diagonally //
            changeWithDirection(&x, &y, team[bestPieceIndex].bestDirection, false);
        }
        cout<< " best move: " << x << "," << y << endl;
        movePiece(Board, team, bestPieceIndex, x, y);
        return true;
    }
    return false;
}
