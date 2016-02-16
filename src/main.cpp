#include <iostream>
#include "../include/CheckersBoard.h"
#include "../include/Player.h"

int main( int argc, char* args[] )
{
    // Checks if init was able to excute //
    if(!init()){
        printf("Could not load!");
    }
    
    Player Player1(true);
    Player Player2(false);
    
    // Loads media such as buttons and sprites //
    loadMedia();
    
    SDL_Event event;
    bool userQuit = false;
    
    // Main loop //
    while(!userQuit){
        
        // Event loop //
        while(SDL_PollEvent(&event)!=0){
            
            // Quits game //
            if(event.type==SDL_QUIT)
            {
                userQuit=true;
            }
            for(int i=0;i<TOTAL_BUTTONS;i++){
                boardButtons[i].handleEvent(&event);
            }
        }
        // Light wood color //
        SDL_SetRenderDrawColor(gRenderer, 0xD4, 0x9A, 0x6A, 0xFF);
        // Refreshs screen //
        SDL_RenderClear(gRenderer);
        
        // Render stuff here //
        Board.drawBoard();
        for(int i=0;i<Player1.team.size()/2;i++){
            boardButtons[i].renderTeam(Player1, i);
        }
        for(int i=12;i<Player1.team.size();i++){
            boardButtons[i].renderTeam(Player2, i);
        }
        
        SDL_RenderPresent(gRenderer);
        SDL_Delay(100);
    }
    
    closeWindow();
    return (EXIT_SUCCESS);
}