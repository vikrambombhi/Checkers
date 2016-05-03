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
    void updateKings();
    
    // for multi turn loop
    bool killWasMade = false;
protected:
    void movePiece(CheckersBoard*, vector<Piece>& ,int, int, int);
    void killPiece(CheckersBoard*, int, int);
    void initTeam();
    bool sameTeam(int,int);
    int pieceTeamIndexByXY(int,int);
    bool topSide;
    int ONE;
    int teamSize = 12;
    int TEAM_NUMBER;
    int ENEMY_TEAM_NUMBER;
    CheckersBoard *Board;
    Button *boardButtons;
    
    // for multi turn loop
    int killerPeiceIndex;
};


#endif /* Player_h */
