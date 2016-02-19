#include <iostream>
#include "../include/CheckersBoard.h"
#include "../include/Player.h"
#include "../include/AI.h"

int main( int argc, char* args[] )
{
    // Calls Application consturctor
    Application App;

    AI Player1(true);
    Player Player2(false);

    SDL_Event event;
    bool userQuit = false;
    int index = 0, column = 0, row = 0, value = 0;

    // Main loop //
    while(!userQuit){

        // Event loop //
        while(SDL_PollEvent(&event)!=0){

            // Quits game //
            if(event.type==SDL_QUIT)
            {
                userQuit=true;
            }
            // Player make move //
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                if (Player2.selectingState == false) {
                    for (int i=0; i<TOTAL_BUTTONS; i++) {
                        if (boardButtons[i].insideButton()) {
                            index = i;
                            // Player selects a piece to move //
                            Player2.selectPiece(&value, &column, &row, index);
                            break;
                        }
                    }
                }
                else{
                    for (int i=0; i<TOTAL_BUTTONS; i++) {
                        if (boardButtons[i].insideButton()) {
                            index = i;
                            // Player selects where the piece should move //
                            Player2.movePiece(value, column, row, index);
                            break;
                        }
                    }
                }
            }
        }
        // MAKE AI MOVE HERE //
        
        // Light wood color //
        SDL_SetRenderDrawColor(gRenderer, 0xD4, 0x9A, 0x6A, 0xFF);
        // Refreshs screen //
        SDL_RenderClear(gRenderer);

        // Render stuff here //
        
        Board.drawBoard();

        // Render whole team //
        index = 0;
        for (int y=0; y<8; y++) {
            for (int x=0; x<8; x++) {
                if((y+x)%2 == 1){
                    boardButtons[index].renderBoardMember(Board, x, y);
                    index++;
                }
            }
        }

        SDL_RenderPresent(gRenderer);
        SDL_Delay(100);
    }
    return (EXIT_SUCCESS);
}
