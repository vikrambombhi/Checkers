//
//  Piece.hpp
//  CheckersProject
//
//  Created by Benjamin Emdon on 2016-02-13.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef Piece_h
#define Piece_h

class Piece {
public:
    Piece();
    void setPoint(int, int);
    int x;
    int y;
    int probability;
};

#endif /* Piece_hpp */
