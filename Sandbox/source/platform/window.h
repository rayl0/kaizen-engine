#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "core/defines.h"
#include "core/types.h"

namespace kz {
class Window {
    SDL_Window* sdl_window_;

    NULL_COPY_AND_ASSIGN(Window)
public:
    Window();
    explicit Window(const std::string& title, u32 width, u32 height,
        const u32& flags = { SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL });
    ~Window();

    void Create(const std::string& title, u32 width, u32 height,
        const u32& flags = { SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL });
    inline bool IsOpen() const { return sdl_window_ != nullptr; }
    void Destroy();

    inline SDL_Window* GetSdlWindow() const { return sdl_window_; }
};
}
