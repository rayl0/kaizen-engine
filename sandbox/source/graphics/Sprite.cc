#include "Sprite.h"

#include <cstdlib>

namespace kz {
Sprite::Sprite()
    : m_tex(nullptr)
    , clip_({ 0, 0, 0, 0 })
{
}
Sprite::Sprite(const Texture& tex)
    : m_tex(&tex)
    , clip_({ 0, 0, (s32)m_tex->getWidth(), (s32)m_tex->getHeight() })
{
}
Sprite::Sprite(const Texture& tex, const SDL_Rect& clip)
    : m_tex(&tex)
    , clip_(clip)
{
}
Sprite::~Sprite()
{
}

void Sprite::draw(const SDL_Rect& dest)
{
    m_tex->draw(dest, &clip_);
}
}
