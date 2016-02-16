#include <iostream>
#include "CheckersBoard.h"

int main( int argc, char* args[] )
{
    // Checks if init was able to excute //
    if(!init()){
        printf("Could not load!");
    }
    
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
        
        SDL_RenderPresent(gRenderer);
        SDL_Delay(100);
    }
    
    closeWindow();
    return (EXIT_SUCCESS);
}