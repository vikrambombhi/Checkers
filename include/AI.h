#ifndef AI_H
#define AI_H

#include <iostream>
#include "../include/Player.h"
#include "../include/CheckersBoard.h"

class AI : public Player
{
    public:
        AI(bool);
        void movePiece(int x, int y, int newX, int newY);
        int threatCheckLeft(int x, int y);
        int threatCheckRight(int x, int y);
        int checkLeft(int x, int y, int left);
        int checkRight(int x, int y, int right);
        void moveCheck(int x, int y, int b);
        void moveChoose();
};

#endif // AI_H
