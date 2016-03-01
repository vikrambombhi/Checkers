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
#include "Button.h"

class CheckersBoard{
public:
    CheckersBoard();
    ~CheckersBoard();
    void drawBoard();
    void drawBoardPeices(int, int, Button*);
    void printBoard();
    std::vector<std::vector<int>> virtualBoard; // Virtual board indexed by [x][y]
};

//extern CheckersBoard Board;
#endif /* CheckersBoard_h */
