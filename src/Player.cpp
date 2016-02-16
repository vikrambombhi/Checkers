//
//  Player.cpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "../include/Player.h"

Player::Player(bool topSide) {
    initTeam(topSide);
}

void Player::initTeam(bool topSide) {
    if (topSide) {
        //----------------------------BLACK TEAM----------------------------\\
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 0
        team[0].x = 1;
        team[0].y = 0;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 1
        team[1].x = 3;
        team[1].y = 0;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 2
        team[2].x = 5;
        team[2].y = 0;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 3
        team[3].x = 7;
        team[3].y = 0;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 4
        team[4].x = 0;
        team[4].y = 1;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 5
        team[5].x = 2;
        team[5].y = 1;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 6
        team[6].x = 4;
        team[6].y = 1;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 7
        team[7].x = 6;
        team[7].y = 1;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 8
        team[8].x = 1;
        team[8].y = 2;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 9
        team[9].x = 3;
        team[9].y = 2;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 10
        team[10].x = 5;
        team[10].y = 2;
        
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 11
        team[11].x = 7;
        team[11].y = 2;
    }
    else {
        //-----------------------------RED TEAM----------------------------\\
        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 0
        team[0].x = 0;
        team[0].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 1
        team[1].x = 2;
        team[1].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 2
        team[2].x = 4;
        team[2].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 3
        team[3].x = 6;
        team[3].y = 7;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 4
        team[4].x = 1;
        team[4].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 5
        team[5].x = 3;
        team[5].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 6
        team[6].x = 5;
        team[6].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 7
        team[7].x = 7;
        team[7].y = 6;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 8
        team[8].x = 0;
        team[8].y = 5;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 9
        team[9].x = 2;
        team[9].y = 5;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 10
        team[10].x = 4;
        team[10].y = 5;

        //Push back new chip created with default constructor.
        team.push_back(Piece());
        //Vector now has 1 element @ index 11
        team[11].x = 6;
        team[11].y = 5;
    }
}