#ifndef AI_H
#define AI_H

#include <iostream>
#include "../include/Player.h"
#include "../include/CheckersBoard.h"

class AI : public Player
{
    public:
        AI(bool);
        int threatCheckLeft(int x, int y);
        int threatCheckRight(int x, int y);
        int checkLeft(int x, int y);
        int checkRight(int x, int y);
        void moveCheck(int x, int y, int b);
        void moveChoose();
};

#endif // AI_H
