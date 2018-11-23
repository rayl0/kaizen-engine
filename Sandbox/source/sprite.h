#pragma once

#include <SDL2/SDL.h>

namespace kz {
struct Sprite {
    SDL_Texture* texture;
    SDL_Rect* source_rect;
    SDL_Rect* destination_rect;
};

Sprite* CreateSprite(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination);
void DrawSprite(SDL_Renderer* renderer, Sprite* sprite);
void DestroySprite(Sprite* sprite);
}
