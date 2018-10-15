//
// Created by Zelda Hessler on 10/13/18.
//

#include "Texture.h"
#include <iostream>

Texture::Texture(SDL_Renderer *renderer, std::string path, int width, int height) {
    _surface = IMG_Load(path.c_str());
    if (_surface == nullptr) {
        std::cerr << "Texture.cpp:12:Error - " << IMG_GetError() << "\n";
        throw SurfaceCreationException();
    }
    _texture = SDL_CreateTextureFromSurface(renderer, _surface);
    if (_texture == nullptr) {
        std::cerr << "Texture.cpp:17:Error - " << SDL_GetError() << "\n";
        throw TextureCreationException();
    }

    _width = width;
    _height = height;
}

Texture::~Texture() {
    SDL_DestroyTexture(_texture);
    SDL_FreeSurface(_surface);
}

void Texture::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip) {
    {
        SDL_Rect renderQuad = {x, y, _width, _height};

        if (clip != nullptr) {
            renderQuad.w = clip->w;
            renderQuad.h = clip->h;
        }

        SDL_RenderCopy(renderer, _texture, clip, &renderQuad);
    }
};

int Texture::getWidth() {
    return _width;
};

int Texture::getHeight() {
    return _height;
};
