//
//  CheckersBoard.h
//  Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef CheckersBoard_h
#define CheckersBoard_h

#include <vector>
#include "Application.h"

class CheckersBoard{
public:
    CheckersBoard();
    void drawBoard();
    void printBoard();
    std::vector<std::vector<int> > virtualBoard; // Virtual board inexed by [x][y]
};

//extern CheckersBoard Board;
#endif /* CheckersBoard_h */
