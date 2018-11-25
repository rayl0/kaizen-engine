#pragma once

#include <SDL2/SDL.h>

#include "core/Defines.h"
#include "core/Types.h"
#include "platform/Window.h"

#include "Texture.h"

namespace kz {
class Renderer {
    SDL_Renderer* m_renderer;

    NULL_COPY_AND_ASSIGN(Renderer)
public:
    Renderer();
    ~Renderer();

    void create(Window& window, u32 flags = { SDL_RENDERER_ACCELERATED });
    void destroy();

    void setClearColor(u8 red, u8 green, u8 blue, u8 alpha);
    void clear();
    void display();

    void draw(const Texture& tex, SDL_Rect source, SDL_Rect dest);
    inline SDL_Renderer* getSdlRenderer() const { return m_renderer; }
};
}
