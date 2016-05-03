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
    int directionValues[4] = {-99999999, -99999999, -99999999, -99999999};
    int bestDirection;
    void findBestDirection();
private:
    bool king;
};

#endif /* Piece_hpp */
