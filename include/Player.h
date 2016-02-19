//
//  Player.h
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef Player_h
#define Player_h

#include "CheckersBoard.h"
#include "Piece.h"
using namespace std;

class Player {
public:
    Player(bool);
    void initTeam(bool);
    void selectPiece(int*, int*, int*, int);
    void movePiece(int, int, int, int);
    vector<Piece> team;
    bool turn;
    bool selectingState;
private:
    bool topSide;
};

extern const int TEAM_SIZE;

#endif /* Player_h */
