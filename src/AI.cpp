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

void AI::updateTeam(vector<vector<int>> &tempBoard, vector<Piece> &teamCopy, bool enemy) {
    // Updates team when team.size() has been altered
    int teamNumber = TEAM_NUMBER;

    if (enemy) {
        teamNumber = ENEMY_TEAM_NUMBER;
    }

    for(int index=0;index<teamCopy.size();index++){
        if (!sameTeam(tempBoard[teamCopy[index].x][teamCopy[index].y], teamNumber)) {
            teamCopy.erase(teamCopy.begin()+index);
            index--;
        }
    }
}

void AI::updateKings(vector<vector<int>> &tempBoard, vector<Piece> &teamCopy, bool enemy) {

    int yToMakeKing = 7 * topSide;

    if (enemy) {
        yToMakeKing = yToMakeKing * !topSide;
    }

    for(int index=0;index<teamCopy.size();index++){
        if (teamCopy[index].y == yToMakeKing && !teamCopy[index].isKing()) {
            teamCopy[index].makeKing();
            tempBoard[teamCopy[index].x][teamCopy[index].y] += 2;
        }
    }
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

int AI::enemyBestPiece(vector<Piece>& pieceVector){

    int smallest = pieceVector[0].potential;
    vector<int> smallestVector;

    for(int i=1;i<pieceVector.size();i++){
        if(smallest < pieceVector[i].potential) {
            smallest = pieceVector[i].potential;
        }
    }

    for(int j=0;j<pieceVector.size();j++){
        if(smallest <= pieceVector[j].potential){
            smallestVector.push_back(j);
        }
    }

    /* initialize random seed: */
    srand(static_cast<unsigned int>(time(NULL)));
    /* generate secret number from 0 to vectorSize*/

    int randIndex = rand() % smallestVector.size();

    return smallestVector[randIndex];
}

int AI::bestPiece(vector<Piece>& pieceVector){

    int largest = pieceVector[0].potential;
    vector<int> largestVector;

    for(int i=1;i<pieceVector.size();i++){
        if(largest < pieceVector[i].potential) {
            largest = pieceVector[i].potential;
        }
    }

    for(int j=0;j<pieceVector.size();j++){
        if(largest <= pieceVector[j].potential){
            largestVector.push_back(j);
        }
    }

    /* initialize random seed: */
    srand(static_cast<unsigned int>(time(NULL)));
    /* generate secret number from 0 to vectorSize*/

    int randIndex = rand() % largestVector.size();

    return largestVector[randIndex];
}

bool AI::makeMove(SDL_Event *event){

    // Init enemyTeam that this class can use
    getEnemyTeam();

    for(int index=0;index<team.size();index++){
        currentIndex = index;

        team[index].directionValues[1] = maxValue(Board->virtualBoard, team, enemyTeam, MAX_DEPTH, RIGHT);        
        team[index].directionValues[0] = maxValue(Board->virtualBoard, team, enemyTeam, MAX_DEPTH, LEFT);

        if (team[index].isKing()) {
            team[index].directionValues[3] = maxValue(Board->virtualBoard, team, enemyTeam, MAX_DEPTH, BACK_RIGHT);
            team[index].directionValues[2] = maxValue(Board->virtualBoard, team, enemyTeam, MAX_DEPTH, BACK_LEFT);
        }
        cout<<"Index: "<<index<<" ("<< team[index].x << "," << team[index].y;
        cout<<") Left: "<<team[index].directionValues[0]<<" Right: "<<team[index].directionValues[1];
        cout<<" bLeft: "<<team[index].directionValues[2]<<" bRight: "<<team[index].directionValues[3]<<endl;

        team[index].findBestDirection();
        team[index].findLargestPotenial();
    }

    int bestPieceIndex = bestPiece(team);
    cout<< "The chosen one: " << bestPieceIndex << " -> ("<< team[bestPieceIndex].x << "," << team[bestPieceIndex].y;

    int x = team[bestPieceIndex].x;
    int y = team[bestPieceIndex].y;

    // Makes sure the move isnt out of bounds //
    if (team[bestPieceIndex].potential != OUT_OF_BOUND) {

        changeWithDirection(x, y, team[bestPieceIndex].bestDirection, false);

        if(sameTeam(Board->virtualBoard[x][y],ENEMY_TEAM_NUMBER)){
            // Changes it again for moving 2 units diagonally //
            changeWithDirection(x, y, team[bestPieceIndex].bestDirection, false);
        }
        cout<<") best move: (" << x << "," << y <<")"<< endl;
        movePiece(Board->virtualBoard, team, bestPieceIndex, x, y);
        return true;
    }
    return false;
}

int AI::valueCalculator(vector<Piece> &teamCopy, vector<Piece> &enemyTeamCopy){

    int value = 0;
    int x,y;

    for(int i=0; i<teamCopy.size(); i++){
        if (teamCopy[i].isKing()) {
            value += 20;
        }
        else{
            value +=10;
        }

        x = teamCopy[i].x;
        y = teamCopy[i].y;

        if ((x == 0 || x==7) || (y==0||y==7)){
            value += 4;
        }
        else if((x == 1 || x==6) || (y==1||y==6)){
            value += 3;
        }
        else if((x == 2 || x==5) || (y==2||y==5)){
            value += 2;
        }
        else if((x == 3 || x==4) || (y==3||y==4)){
            value += 1;
        }

    }

    for(int j=0; j<enemyTeamCopy.size(); j++){
        if (enemyTeamCopy[j].isKing()) {
            value -= 20;
        }
        else{
            value -= 10;
        }

        x = enemyTeamCopy[j].x;
        y = enemyTeamCopy[j].y;

        if ((x == 0 || x==7) || (y==0||y==7)){
            value -= 4;
        }
        else if((x == 1 || x==6) || (y==1||y==6)){
            value -= 3;
        }
        else if((x == 2 || x==5) || (y==2||y==5)){
            value -= 2;
        }
        else if((x == 3 || x==4) || (y==3||y==4)){
            value -= 1;
        }

    }

    return value;
}

bool AI::changeWithDirection(int &x, int &y, Directions direction, bool enemy){
    int one = ONE;

    if (enemy) {
        one = ONE * -1;
    }

    switch (direction) {
        case LEFT:
            x -= 1;
            y += one;
            break;
        case RIGHT:
            x += 1;
            y += one;
            break;
        case BACK_LEFT:
            x -= 1;
            y -= one;
            break;
        case BACK_RIGHT:
            x += 1;
            y -= one;
            break;
        default:
            return false;
            break;
    }

    // Makes sure new values are in bound //
    if(x<0 || y<0 || y>7 || x>7){
        return false;
    }

    return true;
}

bool AI::killCheckArea(vector<vector<int>> &tempBoard, int x, int y, Directions checkDirection, bool enemy){
    // Makes sure direction was able to be changed//
    if(!changeWithDirection(x, y, checkDirection, enemy)){
        return false;
    }
    // Returns true if direction is clear //
    if(tempBoard[x][y] == EMPTY_PIECE){
        return true;
    }
    return false;
}

bool AI::checkNode(vector<vector<int>>& tempBoard, vector<Piece> &teamCopy, vector<Piece> &enemyTeamCopy, Directions direction, bool enemy){
    int x, y;
    int teamNumber = TEAM_NUMBER;
    int enemyTeamNumber = ENEMY_TEAM_NUMBER;

    if (enemy) {
        x = enemyTeamCopy[enemyCurrentIndex].x;
        y = enemyTeamCopy[enemyCurrentIndex].y;
        teamNumber = ENEMY_TEAM_NUMBER;
        enemyTeamNumber = TEAM_NUMBER;
    }
    else{
        x = teamCopy[currentIndex].x;
        y = teamCopy[currentIndex].y;
    }

    // Makes sure the changed x & y values are applied (Just incase)
    if(!changeWithDirection(x , y, direction, enemy)){
        return false;
    }

    // Team piece in the way
    if(sameTeam(tempBoard[x][y], teamNumber)){
        return false;
    }

    // Enemy might be unkillable
    if(sameTeam(tempBoard[x][y], enemyTeamNumber)){
        return killCheckArea(tempBoard, x, y, direction, enemy);
    }

    return true;
}

int AI::maxValue(vector<vector<int>> tempBoard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth, Directions direction){

    bool killMove = false;

    if(!checkNode(tempBoard, teamCopy, enemyTeamCopy, direction, false)){
        return OUT_OF_BOUND;
    }
    int x = teamCopy[currentIndex].x;
    int y = teamCopy[currentIndex].y;

    changeWithDirection(x, y, direction, false);
    if(sameTeam(tempBoard[x][y],ENEMY_TEAM_NUMBER)){
        if(!killCheckArea(tempBoard, x, y, direction, false)){
            return OUT_OF_BOUND;
        }
        else{
            changeWithDirection(x, y, direction, false);
            killMove = true;
        }
    }

    //This should move on the tempBoard
    movePiece(tempBoard, teamCopy, currentIndex, x, y);
    updateKings(tempBoard, teamCopy, false);
    if (killMove) {
        updateTeam(tempBoard, enemyTeamCopy, true);
        if (enemyTeamCopy.size()<=0) {
            return WIN_VALUE;
        }
    }

    if (depth <= 0) {
        return valueCalculator(teamCopy, enemyTeamCopy);
    }
    else{
        return minMove(tempBoard, teamCopy, enemyTeamCopy, depth-1);
    }

}

int AI::minMove(vector<vector<int>> &tempboard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth){

    for(int index=0;index<enemyTeamCopy.size();index++){
        enemyCurrentIndex = index;

        enemyTeamCopy[index].directionValues[1] = minValue(tempboard, teamCopy, enemyTeamCopy, depth, RIGHT);
        enemyTeamCopy[index].directionValues[0] = minValue(tempboard, teamCopy, enemyTeamCopy, depth, LEFT);

        if (enemyTeamCopy[index].isKing()) {
            enemyTeamCopy[index].directionValues[3] = minValue(tempboard, teamCopy, enemyTeamCopy, depth, BACK_RIGHT);
            enemyTeamCopy[index].directionValues[2] = minValue(tempboard, teamCopy, enemyTeamCopy, depth, BACK_LEFT);
        }

        enemyTeamCopy[index].findLargestPotenial();

    }
    int bestPieceIndex = bestPiece(enemyTeamCopy);
    return enemyTeamCopy[bestPieceIndex].potential;
}

int AI::minValue(vector<vector<int>> tempBoard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth, Directions direction){

    bool killMove = false;

    if(!checkNode(tempBoard, teamCopy, enemyTeamCopy, direction, true)){
        return OUT_OF_BOUND;
    }

    int x = enemyTeamCopy[enemyCurrentIndex].x;
    int y = enemyTeamCopy[enemyCurrentIndex].y;

    changeWithDirection(x, y, direction, true);
    if(sameTeam(tempBoard[x][y],TEAM_NUMBER)){
        if(!killCheckArea(tempBoard, x, y, direction, true)){
            return OUT_OF_BOUND;
        }
        else{
            changeWithDirection(x, y, direction, true);
            killMove = true;
        }
    }

    //This should move on the tempBoard
    movePiece(tempBoard, enemyTeamCopy, enemyCurrentIndex, x, y);
    updateKings(tempBoard, enemyTeamCopy, true);
    if (killMove) {
        updateTeam(tempBoard, teamCopy, false);
        if (teamCopy.size()<=0) {
            //smallest number
            return -1 * WIN_VALUE;
        }
    }

    if (depth <= 0) {
        return valueCalculator(teamCopy, enemyTeamCopy);
    }
    else{
        return maxMove(tempBoard, teamCopy, enemyTeamCopy, depth-1);
    }

}

int AI::maxMove(vector<vector<int>> &tempboard, vector<Piece> teamCopy, vector<Piece> enemyTeamCopy, int depth){

    for(int index=0;index<teamCopy.size();index++){
        currentIndex = index;

        teamCopy[index].directionValues[0] = maxValue(tempboard, teamCopy, enemyTeamCopy, depth, LEFT);
        teamCopy[index].directionValues[1] = maxValue(tempboard, teamCopy, enemyTeamCopy, depth, RIGHT);

        if (teamCopy[index].isKing()) {
            teamCopy[index].directionValues[2] = maxValue(tempboard, teamCopy, enemyTeamCopy, depth, BACK_LEFT);
            teamCopy[index].directionValues[3] = maxValue(tempboard, teamCopy, enemyTeamCopy, depth, BACK_RIGHT);
        }

        teamCopy[index].findLargestPotenial();

    }

    int bestPieceIndex = enemyBestPiece(teamCopy);
    return teamCopy[bestPieceIndex].potential;
}
