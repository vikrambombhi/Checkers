#include <SDl2/SDL.h>
#include <stdio.h>
#include <iostream>
#include "SDL_util.h"
#include "CheckersBoard.h"

int main( int argc, char* args[] )
{
    if(!init()){
        printf("Could not load!");
    }
    
    SDL_Event e;
    bool quit = false;
    
    while(!quit){
        while(SDL_PollEvent(&e)!=0){
            //quits game
            if(e.type==SDL_QUIT)
            {
                quit=true;
            }
        }
        
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear(gRenderer);
        
        mainBoard.drawBoard();
        
        SDL_RenderPresent(gRenderer);
        SDL_Delay(100);
    }
    closeWindow();
    return (EXIT_SUCCESS);
}