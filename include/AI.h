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
    bool sameTeam(int,int);
    bool changeWithDirection(int*,int*,Directions);
    bool killCheckArea(int,int,Directions);
    int checkArea(int x, int y, Directions, int points);
    void moveCheck(int index, int depth);
    int bestPieceIndex;
    const int NOTHING = 0;
    const int BLOCK = 50;
    const int KILL_PIECE = 100;
    const int OUT_OF_BOUND = -99999999;
};

#endif // AI_H
