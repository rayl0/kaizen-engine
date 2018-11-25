#pragma once

#include <SDL2/SDL.h>

#include "core/Defines.h"
#include "core/Types.h"

#include "Image.h"

namespace kz {
class Texture {
    SDL_Texture* m_tex;

    u32 m_width;
    u32 m_height;

    NULL_COPY_AND_ASSIGN(Texture)
public:
    Texture();
    explicit Texture(const Image& img);
    ~Texture();

    void create(const Image& img);
    void draw(const SDL_Rect& destination, SDL_Rect* clip = nullptr) const;
    void destroy();

    inline SDL_Texture* getSdlTexture() const { return m_tex; }
    inline const u32& getWidth() const { return m_width; }
    inline const u32& getHeight() const { return m_height; }
};
}
