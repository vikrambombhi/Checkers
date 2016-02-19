#ifndef AI_H
#define AI_H

#include <iostream>
#include "../include/Player.h"
#include "../include/CheckersBoard.h"

class AI : public Player
{
    public:
        AI(bool);
        void moveChoose();
        int updateProb(int x, int y, int val);
};

#endif // AI_H
