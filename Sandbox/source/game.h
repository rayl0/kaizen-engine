#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "types.h"

namespace kz {
class Game {
    SDL_Window* game_window_;
    SDL_Renderer* game_renderer_;

    SDL_Event global_events_;

    bool is_running_;

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
