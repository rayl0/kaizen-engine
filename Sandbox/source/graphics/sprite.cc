#include "sprite.h"

#include <cstdlib>

namespace kz {

Sprite* CreateSprite(SDL_Texture* texture, SDL_Rect* source, SDL_Rect* destination)
{
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));
    sprite->texture = texture;
    sprite->source_rect = source;
    sprite->destination_rect = destination;

    return sprite;
}

void DrawSprite(SDL_Renderer* renderer, Sprite* sprite)
{
    SDL_RenderCopy(renderer, sprite->texture, sprite->source_rect, sprite->destination_rect);
}

void DestroySprite(Sprite* sprite)
{
    free(sprite);
}
}
