//
//  RealPlayer.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-03-02.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef RealPlayer_h
#define RealPlayer_h

#include "Player.h"

class RealPlayer: public Player{
public:
    RealPlayer(bool, CheckersBoard*, Button*);
    ~RealPlayer();
    bool makeMove(SDL_Event *);
private:
    void selectPiece(int, int);
    bool selectedLocationIsValid(int, int, int, bool);
    void highlightValidMoves();
    bool selectingState;
};


#endif /* RealPlayer_h */
