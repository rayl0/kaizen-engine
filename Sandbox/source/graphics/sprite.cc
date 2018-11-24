#include "sprite.h"

#include <cstdlib>

namespace kz {
Sprite::Sprite()
    : tex_(nullptr)
    , clip_({ 0, 0, 0, 0 })
{
}
Sprite::Sprite(const Texture& tex)
    : tex_(&tex)
    , clip_({ 0, 0, (s32)tex_->GetWidth(), (s32)tex_->GetHeight() })
{
}
Sprite::Sprite(const Texture& tex, const SDL_Rect& clip)
    : tex_(&tex)
    , clip_(clip)
{
}
Sprite::~Sprite()
{
}

void Sprite::Draw(const SDL_Rect& dest)
{
    tex_->Draw(dest, &clip_);
}
}
