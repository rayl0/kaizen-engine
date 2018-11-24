#include "texture.h"

#include "core/game.h"

namespace kz {
Texture::Texture()
    : tex_(nullptr)
{
}

Texture::Texture(const Image& img)
    : tex_(nullptr)
{
    Create(img);
}

Texture::~Texture()
{
    Destroy();
}

void Texture::Create(const Image& img)
{
    tex_ = SDL_CreateTextureFromSurface(Game::game_renderer_.GetSdlRenderer(), img.GetSdlSurface());
}

void Texture::Draw(const SDL_Rect& destination, SDL_Rect* clip) const
{
    SDL_RenderCopy(Game::game_renderer_.GetSdlRenderer(), tex_, clip, &destination);
}

void Texture::Destroy()
{
    SDL_DestroyTexture(tex_);
    tex_ = nullptr;
}
} // namespace kz
