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
    int returnBigger(int, int);
    //int tempRecursive(int points, int x, int y, int depth, int left, int right);
    int checkArea(int x, int y, Directions, int , int depth);
    void moveCheck(int index, int depth);
    int currentIndex;
    const int NOTHING = 0;
    const int BLOCK = 50;
    const int KILL_PIECE = 100;
    const int OUT_OF_BOUND = -99999999;
    Directions dList[2] = {LEFT, RIGHT};
};

#endif // AI_H
