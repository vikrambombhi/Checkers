//
//  Player.h
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. 
//

#ifndef Player_h
#define Player_h

#include "CheckersBoard.h"
#include "Piece.h"

using namespace std;

class Button;

class Player{
public:
    Player(bool,CheckersBoard*, Button*);
    ~Player();
    virtual bool makeMove(SDL_Event *);
    vector<Piece> team;
    bool turn;
    void updateTeam();
protected:
    void movePiece(int, int, int);
    void killPiece(int, int);
    void initTeam(bool);
    int pieceTeamIndexByXY(int,int);
    bool topSide;
    int teamSize = 12;
    int teamNumberOnVirtualBoard;
    CheckersBoard *Board;
    Button *boardButtons;
};


#endif /* Player_h */
