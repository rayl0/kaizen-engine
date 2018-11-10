#include "game.h"

namespace kz {
Game::Game()
{
}

Game::~Game()
{
}

u32 Game::execute()
{
    init();
    while (_game_window.isOpen()) {
        tick();
        draw();
        process_events();
    }
    terminate();
    return EXIT_SUCCESS;
}

void Game::init()
{
    _game_window.create(sf::VideoMode(600, 400), "KaizenEngine", sf::Style::Close);
}

void Game::terminate()
{
}

void Game::tick()
{
}

void Game::process_events()
{
    while (_game_window.pollEvent(_game_events)) {
        if (_game_events.type == sf::Event::Closed) {
            _game_window.close();
        }
    }
}

void Game::draw()
{
    _game_window.clear(sf::Color::Yellow);
    _game_window.display();
}
}
