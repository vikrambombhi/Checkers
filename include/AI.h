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
    // State shoud have:
    // 1. Team piece index
    // 2. Current depth
    // 3. Temp board to move pieces on
    
    // New AI Stuff
    int findMax(int,int);
    int findMin(int,int);
    int maxValue(/*state*/);
    int minValue(/*state*/) ;
    int bestMove(/*state*/);
    // Old AI stuff
    int threatCheckArea(int,int,Directions);
    bool changeWithDirection(int*,int*,Directions);
    bool killCheckArea(int,int,Directions);
    int returnRandomIndex(vector<int> bestPiecesList);
    int currentIndex;
    const int OUT_OF_BOUND = -99999999;
    // Temp value:
    const int MAX_DEPTH = 3;
};

#endif // AI_H
