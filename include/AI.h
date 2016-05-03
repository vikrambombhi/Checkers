#ifndef AI_H
#define AI_H

#include "../include/Player.h"
#include "../include/CheckersBoard.h"

enum Directions{
    LEFT,
    RIGHT,
    BACK_LEFT,
    BACK_RIGHT
};

class AI : public Player
{
public:
    AI(bool, CheckersBoard*, Button*);
    ~AI();
    bool makeMove(SDL_Event *);
private:
    // New AI Stuff
    int findMax(int,int);
    int findMin(int,int);
    int maxValue(CheckersBoard tempBoard, int depth, Directions direction, int value);
    int minValue(CheckersBoard tempBoard, int depth, Directions direction, int value);
    bool checkNode(Directions direction);
    int valueCalculator();

    // Old AI stuff
    void getEnemyTeam();
    int threatCheckArea(int,int,Directions);
    bool changeWithDirection(int*,int*,Directions);
    bool killCheckArea(int,int,Directions);
    int returnRandomIndex(vector<int> bestPiecesList);
    int currentIndex; // TODO: RealPlayer uses currentIndex too, should move to Player class
    const int OUT_OF_BOUND = -99999999;
    // Temp max depth value:
    const int MAX_DEPTH = 3;

    // Used for finding min values
    vector<Piece> enemyTeam;

    Directions kingMoves[4] = {LEFT, RIGHT, BACK_LEFT, BACK_RIGHT};
    Directions pieceMoves[2] = {LEFT, RIGHT};
};

#endif // AI_H
