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

class Player {
public:
    Player();
    void initTeam();

    vector<Piece> blackTeam;
    vector<Piece> redTeam;
};



#endif /* Player_h */
