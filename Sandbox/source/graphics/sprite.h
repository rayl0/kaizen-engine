#pragma once

#include <SDL2/SDL.h>

#include "core/defines.h"
#include "core/types.h"
#include "texture.h"

namespace kz {
class Sprite {
    const Texture* tex_;
    SDL_Rect clip_;

    NULL_COPY_AND_ASSIGN(Sprite)
public:
    Sprite();
    explicit Sprite(const Texture& tex);
    Sprite(const Texture& tex, const SDL_Rect& clip);
    ~Sprite();

    void Draw(const SDL_Rect& dest);

    inline const Texture* GetTexture() const { return tex_; }
    inline void SetTexture(const Texture& tex, bool reset_tex_rect = { false })
    {
        tex_ = &tex;
        if (reset_tex_rect = false)
            return;
        clip_ = SDL_Rect{ 0, 0, (s32)tex_->GetWidth(), (s32)tex_->GetHeight() };
    }
    inline void SetTextureRectangle(const SDL_Rect& rect) { clip_ = rect; }
};
}
