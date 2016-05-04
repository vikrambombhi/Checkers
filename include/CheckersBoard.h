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
#include <iostream>
#include "Application.h"
#include "Button.h"

struct pointXY {
    int x;
    int y;
};


class CheckersBoard{
    friend ostream & operator << (ostream &, CheckersBoard &);
public:
    CheckersBoard();
    ~CheckersBoard();
    void drawBoard();
    void drawHighlights();
    void turnHighLightOn(int,int);
    void turnHighLightOff();
    vector<vector<int>> virtualBoard; // Virtual board inexed by [x][y]
    void drawBoardPeices(int, int, Button*);
    bool emptyBoard();
    vector<pointXY> validLocations;
private:
    bool highLight;
    pointXY highLightSelected;
    
};

//extern CheckersBoard Board;
#endif /* CheckersBoard_h */
