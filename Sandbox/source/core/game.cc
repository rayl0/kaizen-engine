#include "game.h"

#include <string>

#include <nlohmann/json.hpp>

#include "graphics/image.h"
#include "graphics/sprite.h"
#include "graphics/texture.h"
#include "input/keyboardinput.h"
#include "settings.h"

using json = nlohmann::json;

namespace kz {

Sprite* sp;
Texture tex;
Image surf;

Renderer Game::game_renderer_;

Game::Game()
{
}

Game::~Game()
{
}

u32 Game::Execute()
{
    Init();
    while (game_window_.IsOpen()) {
        Tick();
        Draw();
        ProcessEvents();
    }
    Terminate();
    return EXIT_SUCCESS;
}

void Game::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    settings_.LoadSettings("./settings.json");

    game_window_.Create(settings_.GetWindowSettings().title, settings_.GetWindowSettings().width,
        settings_.GetWindowSettings().height);

    game_renderer_.Create(game_window_);

    surf.Load("img.png");
    tex.Create(surf);
    sp = CreateSprite(tex.GetSdlTexture(), nullptr, new SDL_Rect{ 50, 100, 400, 400 });

    KeyboardInput::InitKeyboard();
}

void Game::Terminate()
{
    DestroySprite(sp);
}

void Game::Tick()
{
    if (KeyboardInput::GetKeyDown(SDLK_UP))
        sp->destination_rect->y -= 1;
    if (KeyboardInput::GetKeyDown(SDLK_DOWN))
        sp->destination_rect->y += 1;
    if (KeyboardInput::GetKeyDown(SDLK_LEFT))
        sp->destination_rect->x -= 1;
    if (KeyboardInput::GetKeyDown(SDLK_RIGHT))
        sp->destination_rect->x += 1;
}

void Game::ProcessEvents()
{
    while (SDL_PollEvent(&global_events_)) {
        if (global_events_.type == SDL_QUIT) {
            game_window_.Destroy();
        }
    }
}

void Game::Draw()
{
    game_renderer_.SetClearColor(125, 100, 100, 255);
    game_renderer_.Clear();
    tex.Draw({ 0, 0, 100, 100 });
    game_renderer_.Display();
}
}
