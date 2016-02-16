//
//  Piece.cpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "../include/Piece.h"

Piece::Piece() {
    x = 0;
    y = 0;
}

void Piece::setPoint (int xLocation, int yLocation) {
    x = xLocation;
    y = yLocation;
}
