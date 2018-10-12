//Using SDL and standard IO
#include <SDL.h>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *args[]) {
    SDL_Window *window = nullptr;
    SDL_Surface *screenSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) { printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError()); }
    else {
        window = SDL_CreateWindow("SDL Tutorial", 0, 0, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) { printf("Window could not be created! SDL_Error: %s\n", SDL_GetError()); }
        else {
            SDL_SetWindowTitle(window, "RPG Game with SDL2");
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            for (int i = 0; i < 10; i++) {
                SDL_PumpEvents();
                SDL_Delay(1000);
            }
        }
    }
}