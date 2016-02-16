//
//  SDL_util.cpp
//  Checkers
//
//  Created by Jacky Chiu on 2016-02-12.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "SDL_util.h"
#include "../include/Button.h"
#include "../include/Texture.h"

SDL_Window *gWindow=NULL;
SDL_Renderer *gRenderer=NULL;

bool init(){
    
    bool initSuccessful = true;
    
    if(SDL_Init(SDL_INIT_VIDEO)>0)
    {
        printf("Failed init. SDL_ERROR: %s\n",SDL_GetError());
        initSuccessful = false;
        }
        else
        {
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            {
                printf("Warning: Linear texture filtering not enabled!");
            }
            
            gWindow=SDL_CreateWindow("Checkers",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
            
            if(gWindow==NULL)
            {
                printf("Couldnt make window. SDL_Error: %s\n",SDL_GetError());
                initSuccessful = false;
            }
            else
            {
                gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
                if(gRenderer==NULL)
                {
                    printf("Renderer failed. SDL_Error: %s\n",SDL_GetError());
                    initSuccessful = false;
                }
                else
                {
                    SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
                    
                    // Init for img loading
                    int imgFlags = IMG_INIT_PNG;
                    if( !( IMG_Init( imgFlags ) & imgFlags ) )
                    {
                        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                        initSuccessful = false;
                    }
                }
            }
            
            
    }
    return initSuccessful;
}

bool loadMedia(){
    
    bool initSuccessfulful = true;
    
    if (!spriteSheetTexture.loadFromFile("data/CheckerSprite.png")) {
        printf("Could not load sprite");
        initSuccessfulful = false;
    }
    // Initalize Checkers Pieces //
    // Red Piece //
    spriteClips[0].x = 0;
    spriteClips[0].y = 0;
    spriteClips[0].w = BUTTON_WIDTH;
    spriteClips[0].h = BUTTON_HEIGHT;
    // Black Piece //
    spriteClips[1].x = BUTTON_WIDTH;
    spriteClips[1].y = 0;
    spriteClips[1].w = BUTTON_WIDTH;
    spriteClips[1].h = BUTTON_HEIGHT;
    
    int index = 0;
    bool indent = true;
    int xStart;
    
    // Sets points for buttons (top left of button)
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
            boardButtons[index].setPoint(x, y);
            index++;
        }
    }
    
    return initSuccessfulful;
}

void closeWindow(){
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;
    
    SDL_DestroyRenderer(gRenderer);
    gRenderer=NULL;
    
    SDL_Quit();

}