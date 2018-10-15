//
// Created by Zelda Hessler on 10/13/18.
//

#include "SDL.h"
#include "World.h"

World::World() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) throw SdlInitializationException();
    if (IMG_Init(IMG_INIT_PNG) < 0) throw SdlImageInitializationException();

    SDL_CreateWindowAndRenderer(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);

    if (_window == nullptr) throw WindowCreationException();
    if (_renderer == nullptr) throw RendererCreationException();

    SDL_SetWindowTitle(_window, Config::WINDOW_TITLE);
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0x00, 0xFF, 0xFF);
//    SDL_RenderClear(_renderer);
    SDL_UpdateWindowSurface(_window);
}

World::~World() {
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    SDL_Quit();
}

SDL_Renderer *World::get_renderer() {
    if (_renderer == nullptr) throw NoRendererException();

    return _renderer;
}

SDL_Window *World::get_window() {
    if (_window == nullptr) throw NoWindowException();

    return _window;
}
