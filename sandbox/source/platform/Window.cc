#include "Window.h"

namespace kz {
Window::Window()
    : m_window(nullptr)
{
}

Window::Window(const std::string& title, u32 width, u32 height, const u32& flags)
    : m_window(nullptr)
{
    create(title, width, height, flags);
}

Window::~Window()
{
    destroy();
}

void Window::create(const std::string& title, u32 width, u32 height, const u32& flags)
{
    if (isOpen())
        return;

    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, width, height,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
}

void Window::destroy()
{
    if (!isOpen())
        return;

    SDL_DestroyWindow(m_window);
    m_window = nullptr;
}
}
