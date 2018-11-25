#include "Game.h"

#include <string>

#include <nlohmann/json.hpp>

#include "graphics/Image.h"
#include "graphics/Sprite.h"
#include "graphics/Texture.h"
#include "input/KeyboardInput.h"
#include "Settings.h"

using json = nlohmann::json;

namespace kz {

Sprite sp;
Texture tex;
Image surf;

Renderer Game::renderer;

Game::Game()
{
}

Game::~Game()
{
}

u32 Game::execute()
{
    init();
    while (m_window.isOpen()) {
        tick();
        draw();
        processEvents();
    }
    terminate();
    return EXIT_SUCCESS;
}

void Game::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    m_settings.load("./settings.json");

    m_window.create(m_settings.getWindowSettings().title, m_settings.getWindowSettings().width,
        m_settings.getWindowSettings().height);

    renderer.create(m_window, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    surf.load("img.png");
    tex.create(surf);
    sp.setTexture(tex);
    sp.setTextureRectangle({ 0, 0, 600, 600 });
    KeyboardInput::initKeyStates();
}

void Game::terminate()
{
}

void Game::tick()
{
}

void Game::processEvents()
{
    while (SDL_PollEvent(&m_globalEvents)) {
        if (m_globalEvents.type == SDL_QUIT) {
            m_window.destroy();
        }
    }
}

void Game::draw()
{
    renderer.setClearColor(125, 100, 100, 255);
    renderer.clear();
    sp.draw({ 0, 0, 400, 400 });
    sp.draw({ 600, 100, 100, 100 });
    renderer.display();
}
}
