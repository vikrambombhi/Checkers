//
//  Texture.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-14.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#include "../include/Texture.h"
#include "../include/Application.h"

SDL_Rect spriteClips[TOTAL_PIECES];
Texture spriteSheetTexture;
SpriteList currentSprite;

Texture::Texture(){
    currentTexture = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture(){
    free();
}

bool Texture::loadFromFile(std::string path){

    // Frees current texture //
    free();

    SDL_Texture *newTexture;
    // Load image from path //
    SDL_Surface *loadedSurface = IMG_Load(path.c_str());

    if(loadedSurface == NULL){
        printf("Unable to load img from %s! SDL Error: %s\n",path.c_str(),IMG_GetError());
    }
    else{
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if (newTexture == NULL) {
            printf("Unable to create texture from %s! SDL Error: %s\n",path.c_str(), SDL_GetError());
        }
        else{
            // Gets image dimensions //
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
        currentTexture = newTexture;
        return currentTexture != NULL;
}

void Texture::render(int x, int y, SDL_Rect *clip){

    // Sets place to render on screen //
    SDL_Rect renderSpace = {x, y, width, height};

    // Sets rendering space dimensions from clip dimensions //
    if(clip != NULL){
        renderSpace.w = clip->w;
        renderSpace.h = clip->h;
    }

    // Render to screen //
    SDL_RenderCopy(gRenderer, currentTexture, clip, &renderSpace);
}


void Texture::free(){
    if(currentTexture!=NULL){
        SDL_DestroyTexture(currentTexture);
        width = 0;
        height = 0;
    }
}

int Texture::getWidth(){
    return width;
}

int Texture::getHeight(){
    return height;
}
