//
// Created by Zelda Hessler on 10/12/18.
//

#include "GameState.h"

GameState::GameState(World &world) : _world(world) {
    const World &_world(world);
}

/// Executed on every frame before updating, for use in reacting to events.
StateTransition GameState::handle_event() {
    return None();
}

/// Executed repeatedly at stable, predictable intervals (1/60th of a second by default), if this is the active state.
StateTransition GameState::fixed_update() {
    return None();
}

/// Executed on every frame immediately, as fast as the engine will allow (taking into account the frame rate limit),
/// if this is the active state.
StateTransition GameState::update() {
    return None();
}
