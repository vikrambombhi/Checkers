//
//  CheckersBoard.h
//  Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef CheckersBoard_h
#define CheckersBoard_h

#include <vector>
#include "SDL_util.h"
# include "Button.h"

using namespace std;

class CheckersBoard{
public:
    CheckersBoard();
    void drawBoard();
    void printBoard();
    //int buttonPressed(int,int);
    vector<vector<int>> virtualBoard;
};

extern CheckersBoard Board;
#endif /* CheckersBoard_h */
