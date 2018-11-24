#pragma once

#include <SDL2/SDL.h>

#include "core/defines.h"
#include "core/types.h"
#include "platform/window.h"

namespace kz {
class Renderer {
    SDL_Renderer* sdl_renderer_;

    NULL_COPY_AND_ASSIGN(Renderer)
public:
    Renderer();
    ~Renderer();

    void Create(Window& window, u32 flags = { SDL_RENDERER_ACCELERATED });
    void Destroy();

    void SetClearColor(u8 red, u8 green, u8 blue, u8 alpha);
    void Clear();
    void Display();

    void Draw(SDL_Texture* tex, SDL_Rect source, SDL_Rect dest);
    inline SDL_Renderer* GetSdlRenderer() const { return sdl_renderer_; }
};
}
