//
//  ApplicationState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-28.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef ApplicationState_h
#define ApplicationState_h

class ApplicationState{
public:
    virtual void stateEnter() = 0;
    virtual void stateEvent() = 0;
    virtual void stateUpdate() = 0;
    virtual void stateRender() = 0;
    virtual bool stateExit() = 0;
};

#endif /* ApplicationState_h */
