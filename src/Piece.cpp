//
//  Piece.cpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. 
//

#include "../include/Piece.h"

Piece::Piece() {
    x = 0;
    y = 0;
    probability = 0;
    king = false;
}

void Piece::setPoint (int xLocation, int yLocation) {
    x = xLocation;
    y = yLocation;
}

bool Piece::isKing() {
    return king;
}

void Piece::makeKing() {
    king = true;
}