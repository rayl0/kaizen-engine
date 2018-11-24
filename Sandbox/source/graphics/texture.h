#pragma once

#include <SDL2/SDL.h>

#include "core/defines.h"
#include "core/types.h"

#include "image.h"
#include "renderer.h"

namespace kz {
class Texture {
    SDL_Texture* tex_;

    u32 width_;
    u32 height_;

    NULL_COPY_AND_ASSIGN(Texture)
public:
    Texture();
    explicit Texture(const Image& img);
    ~Texture();

    void Create(const Image& img);
    void Draw(const SDL_Rect& destination, SDL_Rect* clip = nullptr) const;
    void Destroy();

    inline SDL_Texture* GetSdlTexture() const { return tex_; }
    inline const u32& GetWidth() const { return width_; }
    inline const u32& GetHeight() const { return height_; }
};
}
