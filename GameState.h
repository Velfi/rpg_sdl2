//
// Created by Zelda Hessler on 10/12/18.
//

#ifndef RPG_SDL2_GAMESTATE_H
#define RPG_SDL2_GAMESTATE_H

#include "World.h"
#include "StateTransition.h"

class GameState {
    const World &_world;

    ~GameState() = default;

public:
    /// See below constructor.
    GameState() = delete;

    /// A gamestate must be provided a ref to the world.
    explicit GameState(World &world);

    /// Executed when the game state begins.
    void on_start();

    /// Executed when the game state exits.
    void on_stop();

    /// Executed when a different game state is pushed onto the stack.
    void on_pause();

    /// Executed when the application returns to this game state once again.
    void on_resume();

    /// Executed on every frame before updating, for use in reacting to events.
    StateTransition handle_event();

    /// Executed repeatedly at stable, predictable intervals (1/60th of a second by default), if this is the active state.
    StateTransition fixed_update();

    /// Executed on every frame immediately, as fast as the engine will allow (taking into account the frame rate limit),
    /// if this is the active state.
    StateTransition update();
};


#endif //RPG_SDL2_GAMESTATE_H
