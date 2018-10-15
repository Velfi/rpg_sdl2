//
// Created by Zelda Hessler on 10/13/18.
//

#ifndef RPG_SDL2_TEXTURE_H
#define RPG_SDL2_TEXTURE_H

#include <SDL_render.h>
#include <string>

struct SurfaceCreationException : public std::exception {
    char const *what() noexcept(true);
};

struct TextureCreationException : public std::exception {
    char const *what() noexcept(true);
};

class Texture {
    SDL_Texture *_texture;
    SDL_Surface *_surface;
    int _width;
    int _height;
public:
    Texture() = delete;

    Texture(SDL_Renderer *renderer, std::string path, int width, int height);

    ~Texture();

    void render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip = nullptr);

    int getWidth();

    int getHeight();
};


#endif //RPG_SDL2_TEXTURE_H
