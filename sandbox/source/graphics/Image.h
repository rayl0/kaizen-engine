#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "core/Defines.h"
#include "core/Types.h"

namespace kz {
class Image {
    SDL_Surface* m_surface;

    u32 m_width;
    u32 m_height;

    NULL_COPY_AND_ASSIGN(Image)
public:
    Image();
    explicit Image(const std::string& file);
    ~Image();

    void load(const std::string& file);
    void free();

    inline SDL_Surface* getSdlSurface() const { return m_surface; }
    inline const u32& getWidth() const { return m_width; }
    inline const u32& getHeight() const { return m_height; }
};
}
