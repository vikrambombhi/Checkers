//
//  Button.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-13.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef Button_h
#define Button_h

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

const int BUTTON_WIDTH = 80;
const int BUTTON_HEIGHT = 80;
const int TOTAL_BUTTONS = 64;

enum Sprites{
    BLACK_PIECES,
    RED_PIECES,
    TOTAL_PIECES
};

class Button{
public:
    Button();
    void setPoint(int,int);
    void render();
private:
    SDL_Point buttonPoint;
};

extern SDL_Rect SpriteClips[TOTAL_PIECES];
extern Button boardButtons[TOTAL_BUTTONS];
extern Sprites currentSprite;

#endif /* Button_h */
