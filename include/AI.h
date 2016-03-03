#ifndef AI_H
#define AI_H

#include "../include/Player.h"
#include "../include/CheckersBoard.h"

enum directions{
    LEFT,
    RIGHT,
    BACK_LEFT,
    BACK_RIGHT
};

enum points{
    NOTHING,
    BLOCK,
    KILL_PIECE
};

class AI : public Player
{
public:
    AI(bool, CheckersBoard*, Button*);
    ~AI();
    bool makeMove(SDL_Event *);
private:
    int threatCheckLeft(int x, int y);
    int threatCheckBackLeft(int x, int y);
    bool killCheckLeft(int x, int y);
    int threatCheckRight(int x, int y);
    int threatCheckBackRight(int x, int y);
    bool killCheckRight(int x, int y);
    int checkLeft(int x, int y, int left);
    int checkRight(int x, int y, int right);
    void moveCheck(int b, int depth);

};

#endif // AI_H
