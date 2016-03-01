//
//  GameObjects.cpp
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//
/*
#include "GameObjects.h"
#include "Texture.h"
#include "Application.h"

SpriteList currentSprite;
const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 32;

GameObjects::GameObjects(){
    spriteSheetTexture = new Texture;
    if (!spriteSheetTexture->loadFromFile("data/CheckerSprite.png")) {
        printf("Could not load sprite");
        //initSuccessfulful = false;
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
}

GameObjects::~GameObjects(){
    if (spriteSheetTexture != NULL) {
        spriteSheetTexture = NULL;
    }
    delete spriteSheetTexture;
}
*/