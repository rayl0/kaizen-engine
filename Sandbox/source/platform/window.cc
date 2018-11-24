#include "window.h"

namespace kz {
Window::Window()
    : sdl_window_(nullptr)
{
}

Window::Window(const std::string& title, u32 width, u32 height, const u32& flags)
    : sdl_window_(nullptr)
{
    Create(title, width, height, flags);
}

Window::~Window()
{
    Destroy();
}

void Window::Create(const std::string& title, u32 width, u32 height, const u32& flags)
{
    if (IsOpen())
        return;

    sdl_window_ = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
}

void Window::Destroy()
{
    if (!IsOpen())
        return;

    SDL_DestroyWindow(sdl_window_);
    sdl_window_ = nullptr;
}
}
