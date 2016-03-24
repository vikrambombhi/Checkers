//
//  ApplicationState.h
//  SDL_Checkers
//
//  Created by Jacky Chiu on 2016-02-28.
//  Copyright © 2016 Jacky Chiu. 
//

#ifndef ApplicationState_h
#define ApplicationState_h

enum StateEnum{
    MENU_STATE,
    GAME_STATE,
    GAME_OVER_STATE
};

class ApplicationState{
public:
    virtual ~ApplicationState();
    virtual void stateEnter() = 0;
    virtual void stateEvent() = 0;
    virtual StateEnum stateUpdate() = 0;
    virtual void stateRender() = 0;
    virtual bool stateExit() = 0;
protected:
    virtual bool loadMedia() = 0;
    StateEnum currentStateEnum;
    StateEnum nextStateEnum;
};

#endif /* ApplicationState_h */
