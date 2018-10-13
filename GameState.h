//
// Created by Zelda Hessler on 10/12/18.
//

#ifndef RPG_SDL2_GAMESTATE_H
#define RPG_SDL2_GAMESTATE_H

enum Trans {
    None,
    Pop,
    Push,
    Switch,
    Quit,
};

class GameState {
public:
    /// Executed when the game state begins.
    void on_start() {};

    /// Executed when the game state exits.
    void on_stop() {};

    /// Executed when a different game state is pushed onto the stack.
    void on_pause() {};

    /// Executed when the application returns to this game state once again.
    void on_resume() {};

    /// Executed on every frame before updating, for use in reacting to events.
    Trans handle_event() {
        return Trans::None;
    }

    /// Executed repeatedly at stable, predictable intervals (1/60th of a second by default), if this is the active state.
    Trans fixed_update() {
        return Trans::None;
    }

    /// Executed on every frame immediately, as fast as the engine will allow (taking into account the frame rate limit),
    /// if this is the active state.
    Trans update() {
        return Trans::None;
    }
};


#endif //RPG_SDL2_GAMESTATE_H
