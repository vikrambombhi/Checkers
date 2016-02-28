//
//  Texture.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-14.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef Texture_h
#define Texture_h

#include "Application.h"

#ifdef _WIN32
    #include <SDL.h>
    #include <SDL_image.h>
#elif __APPLE__
    #include <SDL2/SDL.h>
    #include <SDL2_image/SDL_image.h>
#endif

enum SpriteList{
    EMPTY_PIECE,
    RED_PIECE,
    BLACK_PIECE,
    TOTAL_PIECES
};

class Texture: public Application{
public:
    Texture();
    ~Texture();
    bool loadFromFile(std::string);
    void render(int,int,SDL_Rect*);
    void free();
    int getWidth();
    int getHeight();
private:
    SDL_Texture *currentTexture;
    int width;
    int height;
};

#endif /* Texture_h */
