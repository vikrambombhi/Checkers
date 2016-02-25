//
//  Game.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-25.
//  Copyright © 2016 Jacky Chiu. All rights reserved.
//

#ifndef Game_h
#define Game_h

class Game{
public:
    Game();
    ~Game();
private:
    static const int BUTTON_WIDTH;
    static const int BUTTON_HEIGHT;
    static const int TOTAL_BUTTONS;
    static const int TEAM_SIZE;
};

#endif /* Game_h */
