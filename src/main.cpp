#include <SDl2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "SDL_util.h"
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
    bool quit = false;
    
    // Main loop //
    while(!quit){
        
        // Event loop //
        while(SDL_PollEvent(&event)!=0){
            
            // Quits game //
            if(event.type==SDL_QUIT)
            {
                quit=true;
            }
        }
        // Refreshs screen //
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(gRenderer);
        
        Board.drawBoard();
        
        SDL_RenderPresent(gRenderer);
        SDL_Delay(100);
    }
    
    closeWindow();
    return (EXIT_SUCCESS);
}