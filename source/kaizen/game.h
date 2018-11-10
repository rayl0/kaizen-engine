#pragma once

#include <SFML/Graphics.hpp>
#include <entityx/entityx.h>

#include "types.h"

namespace kz {
class Game {
    entityx::EntityX _entity_world;
    sf::RenderWindow _game_window;
    sf::Event _game_events;

public:
    Game();
    ~Game();

    u32 execute();

private:
    void init();
    void terminate();
    void tick();
    void process_events();
    void draw();
};
} // namespace kz
