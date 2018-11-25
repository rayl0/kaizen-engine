#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "core/Defines.h"
#include "core/Types.h"

namespace kz {
class Window {
    SDL_Window* m_window;

    NULL_COPY_AND_ASSIGN(Window)
public:
    Window();
    explicit Window(const std::string& title, u32 width, u32 height,
        const u32& flags = { SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL });
    ~Window();

    void create(const std::string& title, u32 width, u32 height,
        const u32& flags = { SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL });
    inline bool isOpen() const { return m_window != nullptr; }
    void destroy();

    inline SDL_Window* getSdlWindow() const { return m_window; }
};
}
