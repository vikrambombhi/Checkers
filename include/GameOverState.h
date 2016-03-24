//
//  GameOverState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-03-23.
//  Copyright © 2016 Jacky Chiu.

#ifndef GameOverState_h
#define GameOverState_h

#include "ApplicationState.h"

class GameOverState: public ApplicationState{
public:
    GameOverState();
    ~GameOverState();
    void stateEnter();
    void stateEvent();
    StateEnum stateUpdate();
    void stateRender();
    bool stateExit();
private:
    bool loadMedia();
    bool userQuit;
};

#endif /* GameOverState_h */
