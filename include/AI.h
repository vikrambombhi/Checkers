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
    int extentValue(int);
    bool changeWithDirection(int*,int*,Directions);
    bool killCheckArea(int,int,Directions);
    double returnBigger(int, int);
    int returnRandomIndex(vector<int> bestPiecesList);
    int checkArea(int x, int y, Directions, int , int depth, int maxDepth, bool isKing);
    void moveCheck(int index, int depth);
    int currentIndex;
    bool killMove;
    const int NOTHING = 0;
    const int BLOCK = 75;
    const int KILL_PIECE = 500;
    const int OUT_OF_BOUND = -99999999;
};

#endif // AI_H
