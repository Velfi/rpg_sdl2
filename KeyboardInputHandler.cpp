//
// Created by Zelda Hessler on 10/12/18.
//

#include "KeyboardInputHandler.h"

void KeyboardInputHandler::beginNewFrame() {
    this->_pressedKeys.clear();
    this->_releasedKeys.clear();
}

void KeyboardInputHandler::keyDownEvent(const SDL_Event &event) {
    this->_pressedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = true;
}

void KeyboardInputHandler::keyUpEvent(const SDL_Event &event) {
    this->_releasedKeys[event.key.keysym.scancode] = true;
    this->_heldKeys[event.key.keysym.scancode] = false;
}

bool KeyboardInputHandler::wasKeyPressed(SDL_Scancode key) {
    return this->_pressedKeys[key];
}

bool KeyboardInputHandler::wasKeyReleased(SDL_Scancode key) {
    return this->_releasedKeys[key];
}

bool KeyboardInputHandler::isKeyHeld(SDL_Scancode key) {
    return this->_heldKeys[key];
}