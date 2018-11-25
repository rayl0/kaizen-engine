#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics/Renderer.h"
#include "platform/Window.h"
#include "Settings.h"
#include "Types.h"

namespace kz {
class Game {
    Window m_window;

    Settings m_settings;

    SDL_Event m_globalEvents;

public:
    static Renderer renderer;

public:
    Game();
    ~Game();

    u32 execute();

private:
    void init();
    void terminate();
    void tick();
    void processEvents();
    void draw();
};
} // namespace kz
