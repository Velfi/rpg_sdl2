//Using SDL and standard IO
#include <SDL.h>
#include <iostream>

#include "KeyboardInputHandler.h"
#include "World.h"
#include "Texture.h"

enum FULLSCREEN_STATE {
    WINDOWED,
    FULLSCREEN,
};

Uint32 fps_print_callback(Uint32 interval, void *param) {
    World *world = nullptr;
    if (param) {
        world = (World *) param;
        std::cout << "FPS: " << world->get_fps() << "\n";
    }

    SDL_AddTimer(5000, fps_print_callback, world);

    return interval;
}

int main(int argc, char *args[]) {
    auto *world = new World();
    auto test_texture = new Texture(world->get_renderer(), "../resources/zelda.png", 1126, 2000);
    float zelda_x = 0.0, zelda_y = 0.0;
    FULLSCREEN_STATE fullscreen_state = FULLSCREEN_STATE::WINDOWED;
    bool drawn = false;
    double FPS = 60;
    double next_time;

    SDL_AddTimer(1000, fps_print_callback, world);

    SDL_Event event;
    KeyboardInputHandler keyboardInputHandler;

    auto LAST = SDL_GetPerformanceCounter();
    next_time = (double) SDL_GetTicks() + (1000.0 / FPS);
    world->fps_init();
    while (!world->should_quit) {
        keyboardInputHandler.beginNewFrame();
        auto NOW = SDL_GetPerformanceCounter();

        auto delta_time = (NOW - LAST) / (double) SDL_GetPerformanceFrequency();

        if (!drawn) {
            SDL_RenderClear(world->get_renderer());
            test_texture->render(world->get_renderer(), zelda_x, zelda_y, nullptr);
            drawn = true;
        }
        if ((Uint32) next_time <= SDL_GetTicks()) {
            SDL_RenderPresent(world->get_renderer());
            world->fps_tick();

            next_time += 1000.0 / FPS;
            drawn = false;
        }

        while (SDL_PollEvent(&event)) {
            SDL_PumpEvents();

            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.repeat == 0) {
                        keyboardInputHandler.keyDownEvent(event);
                    }
                    break;
                case SDL_KEYUP:
                    keyboardInputHandler.keyUpEvent(event);
                    break;
                case SDL_QUIT:
                    world->should_quit = true;
                    break;
                default:
                    break;
            }
        }

        if (keyboardInputHandler.wasKeyPressed(SDL_SCANCODE_ESCAPE)) world->should_quit = true;

        if (keyboardInputHandler.wasKeyPressed(SDL_SCANCODE_RETURN)) {
            printf("Enter Key was pressed! dt is: %f\n", delta_time);
        }

        if (keyboardInputHandler.isKeyHeld(SDL_SCANCODE_D)) zelda_x += (delta_time * 500);
        if (keyboardInputHandler.isKeyHeld(SDL_SCANCODE_A)) zelda_x -= (delta_time * 500);
        if (keyboardInputHandler.isKeyHeld(SDL_SCANCODE_S)) zelda_y += (delta_time * 500);
        if (keyboardInputHandler.isKeyHeld(SDL_SCANCODE_W)) zelda_y -= (delta_time * 500);

        if (keyboardInputHandler.wasKeyPressed(SDL_SCANCODE_F)) {
            switch (fullscreen_state) {
                case FULLSCREEN:
                    fullscreen_state = WINDOWED;
                    SDL_SetWindowFullscreen(world->get_window(), 0);
                    break;
                case WINDOWED:
                    fullscreen_state = FULLSCREEN;
                    SDL_SetWindowFullscreen(world->get_window(), SDL_WINDOW_FULLSCREEN_DESKTOP);
                    break;
            }
        }

        LAST = NOW;
    }

    delete world;

    return 0;
}
