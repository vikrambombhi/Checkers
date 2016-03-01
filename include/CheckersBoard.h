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
#include <iostream>
#include "Application.h"
#include "Button.h"

using namespace std;

class CheckersBoard{
    friend ostream & operator << (ostream &, CheckersBoard &);
public:
    CheckersBoard();
    void drawBoard();
    vector<vector<int> > virtualBoard; // Virtual board inexed by [x][y]
};

extern CheckersBoard Board;
#endif /* CheckersBoard_h */
