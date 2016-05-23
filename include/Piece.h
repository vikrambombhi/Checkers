//
//  Piece.hpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. 
//

#ifndef Piece_h
#define Piece_h

#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

enum Directions{
    LEFT,
    RIGHT,
    BACK_LEFT,
    BACK_RIGHT
};

using namespace std;

class Piece{
public:
    Piece();
    void setPoint(int, int);
    bool isKing();
    void makeKing();
    int x;
    int y;
    int potential;
    int directionValues[4] = {-999,-999,-999,-999};
    Directions bestDirection;
    void findBestDirection();
    void findLargestPotenial();
private:
    bool king;
};

#endif /* Piece_hpp */
