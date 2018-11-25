#include "Renderer.h"

namespace kz {
Renderer::Renderer()
    : m_renderer(nullptr)
{
}
Renderer::~Renderer()
{
    destroy();
}
void Renderer::create(Window& window, u32 flags)
{
    if (m_renderer != nullptr)
        return;
    m_renderer = SDL_CreateRenderer(window.getSdlWindow(), 1, flags);
}
void Renderer::destroy()
{
    if (m_renderer == nullptr)
        return;
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
}
void Renderer::setClearColor(u8 red, u8 green, u8 blue, u8 alpha)
{
    SDL_SetRenderDrawColor(m_renderer, red, green, blue, alpha);
}
void Renderer::clear()
{
    SDL_RenderClear(m_renderer);
}
void Renderer::display()
{
    SDL_RenderPresent(m_renderer);
}
void Renderer::draw(const Texture& tex, SDL_Rect source, SDL_Rect dest)
{
    SDL_RenderCopy(m_renderer, tex.getSdlTexture(), &source, &dest);
}
}
