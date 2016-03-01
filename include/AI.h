#ifndef AI_H
#define AI_H

#include <iostream>
#include "../include/Player.h"
#include "../include/CheckersBoard.h"

class AI : public Player
{
    public:
        AI(bool, CheckersBoard*, Button*);
        ~AI();
        int updateProb(int x, int y, int val, int times);
        void movePiece(int, int);
        void moveChoose();
};

#endif // AI_H
