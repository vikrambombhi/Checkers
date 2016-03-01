//
//  MenuState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-29.
//  Copyright © 2016 Jacky Chiu.
//

#ifndef MenuState_h
#define MenuState_h
#include "ApplicationState.h"

class MenuState: public ApplicationState{
public:
    MenuState();
    ~MenuState();
    void stateEnter();
    void stateEvent();
    void stateUpdate();
    void stateRender();
    bool stateExit();
private:
    bool loadMedia();
};


#endif /* MenuState_h */
