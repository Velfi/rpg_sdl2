//
// Created by Zelda Hessler on 10/13/18.
//

#ifndef RPG_SDL2_WORLD_H
#define RPG_SDL2_WORLD_H

#include "SDL.h"
#include <SDL_video.h>
#include <SDL_render.h>
#include <SDL_events.h>
#include <SDL_image.h>
#include <exception>
#include "Config.h"

const int FRAME_AVG_AMOUNT = 10;

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
    SDL_Rect _screen_rect{0, 0, Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT};

    // An array to store frame times:
    Uint32 _frame_times[FRAME_AVG_AMOUNT];

// Last calculated SDL_GetTicks
    Uint32 _frame_time_last;

// total frames rendered
    Uint32 _frame_count;

// the value you want
    float _frames_per_second;
public:
    bool should_quit = false;

    World();

    ~World();

    SDL_Renderer *get_renderer();

    SDL_Window *get_window();

    void set_fullscreen(bool is_fullscreen);

    void fps_init();

    void fps_tick();

    float get_fps();
};

#endif //RPG_SDL2_WORLD_H
