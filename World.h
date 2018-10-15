//
// Created by Zelda Hessler on 10/13/18.
//

#ifndef RPG_SDL2_WORLD_H
#define RPG_SDL2_WORLD_H

#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include <exception>
#include "Config.h"

struct NoRendererException : public std::exception {
    char const *what() noexcept(true);
};

struct NoWindowException : public std::exception {
    char const *what() noexcept(true);
};

struct WindowCreationException : public std::exception {
    char const *what() noexcept(true);
};

struct RendererCreationException : public std::exception {
    char const *what() noexcept(true);
};

struct SdlInitializationException : public std::exception {
    char const *what() noexcept(true);
};

struct SdlImageInitializationException : public std::exception {
    char const *what() noexcept(true);
};

class World {
    SDL_Renderer *_renderer = nullptr;
    SDL_Window *_window = nullptr;
    SDL_Event *_event = nullptr;
    SDL_Rect _screen_clear_rect{0, 0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT};
public:
    bool should_quit = false;

    World();

    ~World();

    SDL_Renderer *get_renderer();

    SDL_Window *get_window();
};

#endif //RPG_SDL2_WORLD_H
