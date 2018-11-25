#include "Texture.h"

#include "core/Game.h"

namespace kz {
Texture::Texture()
    : m_tex(nullptr)
{
}

Texture::Texture(const Image& img)
    : m_tex(nullptr)
{
    create(img);
}

Texture::~Texture()
{
    destroy();
}

void Texture::create(const Image& img)
{
    m_tex = SDL_CreateTextureFromSurface(Game::renderer.getSdlRenderer(), img.getSdlSurface());
    m_width = img.getWidth();
    m_height = img.getHeight();
}

void Texture::draw(const SDL_Rect& destination, SDL_Rect* clip) const
{
    SDL_RenderCopy(Game::renderer.getSdlRenderer(), m_tex, clip, &destination);
}

void Texture::destroy()
{
    SDL_DestroyTexture(m_tex);
    m_tex = nullptr;
}
} // namespace kz
