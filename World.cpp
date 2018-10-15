//
// Created by Zelda Hessler on 10/13/18.
//

#include "World.h"

World::World() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0) throw SdlInitializationException();
    if (IMG_Init(IMG_INIT_PNG) < 0) throw SdlImageInitializationException();

    SDL_CreateWindowAndRenderer(Config::SCREEN_WIDTH, Config::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);

    if (_window == nullptr) throw WindowCreationException();
    if (_renderer == nullptr) throw RendererCreationException();

    SDL_SetWindowTitle(_window, Config::WINDOW_TITLE);
    SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(_renderer);
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

void World::set_fullscreen(bool is_fullscreen) {
    if (is_fullscreen) {
        SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
    } else {
        SDL_SetWindowFullscreen(_window, 0);
    }
}

// This function gets called once on startup.
void World::fps_init() {

    // Set all frame times to 0ms.
    memset(_frame_times, 0, sizeof(_frame_times));
    _frame_count = 0;
    _frames_per_second = 0;
    _frame_time_last = SDL_GetTicks();

}

void World::fps_tick() {

    Uint32 frame_times_index;
    Uint32 get_ticks;
    Uint32 count;
    Uint32 i;

    // frametimesindex is the position in the array. It ranges from 0 to FRAME_AVG_AMOUNT.
    // This value rotates back to 0 after it hits FRAME_AVG_AMOUNT.
    frame_times_index = _frame_count % FRAME_AVG_AMOUNT;

    // store the current time
    get_ticks = SDL_GetTicks();

    // save the frame time value
    _frame_times[frame_times_index] = get_ticks - _frame_time_last;

    // save the last frame time for the next fpsthink
    _frame_time_last = get_ticks;

    // increment the frame count
    _frame_count++;

    // Work out the current framerate

    // The code below could be moved into another function if you don't need the value every frame.

    // I've included a test to see if the whole array has been written to or not. This will stop
    // strange values on the first few (FRAME_AVG_AMOUNT) frames.
    if (_frame_count < FRAME_AVG_AMOUNT) {

        count = _frame_count;

    } else {

        count = FRAME_AVG_AMOUNT;

    }

    // add up all the values and divide to get the average frame time.
    _frames_per_second = 0;
    for (i = 0; i < count; i++) {

        _frames_per_second += _frame_times[i];

    }

    _frames_per_second /= count;

    // now to make it an actual frames per second value...
    _frames_per_second = 1000.f / _frames_per_second;

}

float World::get_fps() {
    return _frames_per_second;
}
