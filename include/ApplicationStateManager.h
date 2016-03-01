//
//  ApplicationStateManager.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-28.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef ApplicationStateManager_h
#define ApplicationStateManager_h

class ApplicationState;

class ApplicationStateManager{
public:
    ApplicationStateManager();
    ~ApplicationStateManager();
    void stateEnter();
    void stateEvent();
    void stateUpdate();
    void stateRender();
    bool stateExit();
    ApplicationState *currentState;
};

#endif /* ApplicationStateManager_h */
