//
// Created by Zelda Hessler on 10/12/18.
//

#ifndef RPG_SDL2_KEYBOARD_EVENT_HANDLER_H
#define RPG_SDL2_KEYBOARD_EVENT_HANDLER_H

#include "SDL.h"
#include <map>

class KeyboardInputHandler {
    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;
public:
    void beginNewFrame();

    void keyDownEvent(const SDL_Event &event);

    void keyUpEvent(const SDL_Event &event);

    bool wasKeyPressed(SDL_Scancode key);

    bool wasKeyReleased(SDL_Scancode key);

    bool isKeyHeld(SDL_Scancode key);
};


#endif //RPG_SDL2_KEYBOARD_EVENT_HANDLER_H
