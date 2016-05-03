//
//  Piece.cpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. 
//

#include "../include/Piece.h"
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

Piece::Piece() {
    x = 0;
    y = 0;
    potential = 0;
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

void Piece::findBestDirection(){
    
    int largest = directionValues[0];
    vector<int> largestVector;
    
    for (int i=1; i<4; i++) {
        if (largest < directionValues[i]) {
            largest = directionValues[i];
        }
    }
    
    for(int j=0; j<4; j++){
        if (largest <= directionValues[j]) {
            largestVector.push_back(directionValues[j]);
        }
    }
    
    srand(static_cast<unsigned int>(time(NULL)));
    bestDirection = rand() % largestVector.size();
    potential = largest;
}