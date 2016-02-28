//
//  CheckersBoard.cpp
//  Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. 
//

#include "../include/CheckersBoard.h"
#include "GameState.h"

CheckersBoard::CheckersBoard(){
    for (int y = 0; y < 8; y++)
    {
        vector<int> rowVector;
        for (int x = 0; x < 8; x++)
        {
            rowVector.push_back(0);
        }
        virtualBoard.push_back(rowVector);
    }
}

void CheckersBoard::drawBoard(){
    
    bool indent = false;
    int xStart;
    // Dark wood colour //
    SDL_SetRenderDrawColor( gRenderer, 0x55, 0x27, 0x00, 0xFF );
    
    for(int y=0;y<SCREEN_HEIGHT;y+=BUTTON_HEIGHT){
        if (indent) {
            xStart = BUTTON_WIDTH;
            indent = false;
        }
        else{
            xStart = 0;
            indent = true;
        }
        for(int x=xStart;x<SCREEN_WIDTH;x+=2*BUTTON_WIDTH){
            SDL_Rect redRect = {x, y, BUTTON_WIDTH, BUTTON_HEIGHT};
            SDL_RenderFillRect( gRenderer, &redRect);
        }
    }
}

void CheckersBoard::printBoard(){
    printf("========\n");
    for (int y=0; y<8; y++) {
        for (int x=0; x<8; x++) {
            if ((y + x) % 2 == 1) {
                printf("%i", virtualBoard[x][y]);
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
