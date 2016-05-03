#ifndef AI_H
#define AI_H

#include "../include/Player.h"
#include "../include/CheckersBoard.h"

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
    int minMove(CheckersBoard tempBoard, int depth, Directions direction, int value);
    bool checkNode(Directions direction, bool enemy);
    int valueCalculator();

    // Old AI stuff
    void getEnemyTeam();
    bool changeWithDirection(int*,int*,Directions, bool);
    bool killCheckArea(int,int,Directions, bool);
    int bestPiece(vector<Piece>);
    //int currentIndex; // TODO: RealPlayer uses currentIndex too, should move to Player class
    const int OUT_OF_BOUND = -99999999;
    // Temp max depth value:
    const int MAX_DEPTH = 3;

    // Used for finding min values
    vector<Piece> enemyTeam;
    int enemyCurrentIndex;
};

#endif // AI_H
