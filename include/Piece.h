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
    bool isKing();
    void makeKing();
    int x;
    int y;
    int probability;
    int leftVright;
private:
    bool king;
};

#endif /* Piece_hpp */
