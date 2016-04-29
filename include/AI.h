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
    int threatCheckArea(int,int,Directions);
    bool changeWithDirection(int*,int*,Directions);
    bool killCheckArea(int,int,Directions);
    int returnRandomIndex(vector<int> bestPiecesList);
    int currentIndex;
    const int OUT_OF_BOUND = -99999999;
};

#endif // AI_H
