#include "renderer.h"

namespace kz {
Renderer::Renderer()
    : sdl_renderer_(nullptr)
{
}
Renderer::~Renderer()
{
    Destroy();
}
void Renderer::Create(Window& window, u32 flags)
{
    if (sdl_renderer_ != nullptr)
        return;
    sdl_renderer_ = SDL_CreateRenderer(window.GetSdlWindow(), 1, flags);
}
void Renderer::Destroy()
{
    if (sdl_renderer_ == nullptr)
        return;
    SDL_DestroyRenderer(sdl_renderer_);
    sdl_renderer_ = nullptr;
}
void Renderer::SetClearColor(u8 red, u8 green, u8 blue, u8 alpha)
{
    SDL_SetRenderDrawColor(sdl_renderer_, red, green, blue, alpha);
}
void Renderer::Clear()
{
    SDL_RenderClear(sdl_renderer_);
}
void Renderer::Display()
{
    SDL_RenderPresent(sdl_renderer_);
}
void Renderer::Draw(SDL_Texture* tex, SDL_Rect source, SDL_Rect dest)
{
    SDL_RenderCopy(sdl_renderer_, tex, &source, &dest);
}
}
