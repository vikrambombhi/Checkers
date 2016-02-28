#ifndef AI_H
#define AI_H

#include <iostream>
#include "../include/Player.h"
#include "../include/CheckersBoard.h"

class AI : public Player
{
    public:
        AI(bool, CheckersBoard*, Button*);
        int updateProb(int x, int y, int val, int times);
        void movePiece(int, int);
        void moveChoose();
private:
    CheckersBoard *Board;
    Button *boardButtons;
};

#endif // AI_H
