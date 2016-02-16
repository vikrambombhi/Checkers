//
//  Player.cpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "../include/Player.h"

Player::Player() {
    initTeam();
}

void Player::initTeam() {
    //----------------------------BLACK TEAM----------------------------\\
    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 0
    blackTeam[0].x = 1;
    blackTeam[0].y = 0;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 1
    blackTeam[1].x = 3;
    blackTeam[1].y = 0;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 2
    blackTeam[2].x = 5;
    blackTeam[2].y = 0;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 3
    blackTeam[3].x = 7;
    blackTeam[3].y = 0;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 4
    blackTeam[4].x = 0;
    blackTeam[4].y = 1;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 5
    blackTeam[5].x = 2;
    blackTeam[5].y = 1;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 6
    blackTeam[6].x = 4;
    blackTeam[6].y = 1;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 7
    blackTeam[7].x = 6;
    blackTeam[7].y = 1;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 8
    blackTeam[8].x = 1;
    blackTeam[8].y = 2;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 9
    blackTeam[9].x = 3;
    blackTeam[9].y = 2;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 10
    blackTeam[10].x = 5;
    blackTeam[10].y = 2;

    //Push back new chip created with default constructor.
    blackTeam.push_back(Piece());
    //Vector now has 1 element @ index 11
    blackTeam[11].x = 7;
    blackTeam[11].y = 2;

    //-----------------------------RED TEAM----------------------------\\
    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 0
    redTeam[0].x = 0;
    redTeam[0].y = 7;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 1
    redTeam[1].x = 2;
    redTeam[1].y = 7;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 2
    redTeam[2].x = 4;
    redTeam[2].y = 7;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 3
    redTeam[3].x = 6;
    redTeam[3].y = 7;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 4
    redTeam[4].x = 1;
    redTeam[4].y = 6;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 5
    redTeam[5].x = 3;
    redTeam[5].y = 6;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 6
    redTeam[6].x = 5;
    redTeam[6].y = 6;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 7
    redTeam[7].x = 7;
    redTeam[7].y = 6;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 8
    redTeam[8].x = 0;
    redTeam[8].y = 5;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 9
    redTeam[9].x = 2;
    redTeam[9].y = 5;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 10
    redTeam[10].x = 4;
    redTeam[10].y = 5;

    //Push back new chip created with default constructor.
    redTeam.push_back(Piece());
    //Vector now has 1 element @ index 11
    redTeam[11].x = 6;
    redTeam[11].y = 5;
}