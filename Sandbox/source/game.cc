#include "game.h"

#include <string>

#include <nlohmann/json.hpp>

#include "keyboardinput.h"
#include "settings.h"
#include "sprite.h"

using json = nlohmann::json;

namespace kz {

Sprite* sp;
SDL_Texture* tex;
SDL_Surface* surf;
Settings settings;

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
}

Game::~Game()
{
}

u32 Game::Execute()
{
    Init();
    while (is_running_) {
        Tick();
        Draw();
        ProcessEvents();
    }
    Terminate();
    return EXIT_SUCCESS;
}

void Game::Init()
{
    is_running_ = true;
    settings.LoadSettings("./settings.json");

    game_window_
        = SDL_CreateWindow(settings.GetWindowSettings().title.c_str(), SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED, settings.GetWindowSettings().width, settings.GetWindowSettings().height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    game_renderer_ = SDL_CreateRenderer(game_window_, 1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    surf = IMG_Load("img.png");
    tex = SDL_CreateTextureFromSurface(game_renderer_, surf);
    sp = CreateSprite(tex, nullptr, new SDL_Rect{ 50, 100, 400, 400 });

    KeyboardInput::InitKeyboard();
}

void Game::Terminate()
{
    SDL_DestroyWindow(game_window_);
    SDL_DestroyRenderer(game_renderer_);
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
            is_running_ = false;
        }
    }
}

void Game::Draw()
{
    SDL_SetRenderDrawColor(game_renderer_, 0, 100, 100, 255);
    SDL_RenderClear(game_renderer_);
    DrawSprite(game_renderer_, sp);
    SDL_RenderPresent(game_renderer_);
}
}
