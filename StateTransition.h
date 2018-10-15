//
// Created by Zelda Hessler on 10/13/18.
//

#ifndef RPG_SDL2_STATETRANSITION_H
#define RPG_SDL2_STATETRANSITION_H

//#include "GameState.h"

class StateTransition {
//public:
//    GameState next_state = nullptr;
};

class None : public StateTransition {
};

class Pop : public StateTransition {
};

class Push : public StateTransition {
};

class Switch : public StateTransition {
};

class Quit : public StateTransition {
};

#endif //RPG_SDL2_STATETRANSITION_H
