#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "core/defines.h"
#include "core/types.h"

namespace kz {
class Image {
    SDL_Surface* surf_;

    u32 width_;
    u32 height_;

    NULL_COPY_AND_ASSIGN(Image)
public:
    Image();
    explicit Image(const std::string& file);
    ~Image();

    void Load(const std::string& file);
    void Free();

    inline SDL_Surface* GetSdlSurface() const { return surf_; }
    inline const u32& GetWidth() const { return width_; }
    inline const u32& GetHeight() const { return height_; }
};
}
