#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "graphics/renderer.h"
#include "platform/window.h"
#include "settings.h"
#include "types.h"

namespace kz {
class Game {
    Window game_window_;

    Settings settings_;

    SDL_Event global_events_;

public:
    static Renderer game_renderer_;

public:
    Game();
    ~Game();

    u32 Execute();

private:
    void Init();
    void Terminate();
    void Tick();
    void ProcessEvents();
    void Draw();
};
} // namespace kz
