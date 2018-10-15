//Using SDL and standard IO
#include <SDL.h>

#include "KeyboardInputHandler.h"
#include "World.h"
#include "Texture.h"

int main(int argc, char *args[]) {

    auto *world = new World();
    auto test_texture = new Texture(world->get_renderer(), "../resources/zelda.png", 1126, 2000);
    SDL_Event event;
    KeyboardInputHandler keyboardInputHandler;

    while (!world->should_quit) {
        keyboardInputHandler.beginNewFrame();
        test_texture->render(world->get_renderer(), 0, 0, nullptr);
        SDL_RenderPresent(world->get_renderer());
        SDL_Delay(16);

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

        if (keyboardInputHandler.wasKeyPressed(SDL_SCANCODE_RETURN)) {
            printf("Enter Key was pressed!");
        }
    }

    delete world;

    return 0;
}
