//
//  CheckersBoard.cpp
//  Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "CheckersBoard.h"

CheckersBoard::CheckersBoard(){
    for (int y = 0; y < 8; y++)
    {
        vector<int> rowVector;
        for (int x = 0; x < 8; x++)
        {
            rowVector.push_back(0);
        }
        vituralBoard.push_back(rowVector);
    }
}
void CheckersBoard::drawBoard(){
    
    for(int x=buttonWidth;x<SCREEN_WIDTH;x+=buttonWidth)
    {
        SDL_RenderDrawLine( gRenderer, x, 0, x, SCREEN_HEIGHT);
    }
    
    for(int y=buttonHeight;y<SCREEN_HEIGHT;y+=buttonHeight)
    {
        SDL_RenderDrawLine( gRenderer, 0, y, SCREEN_WIDTH, y);
    }
}

void CheckersBoard::printBoard(){
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            printf("%i",vituralBoard[i][j]);
        }
        printf("\n");
    }
}