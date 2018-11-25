#pragma once

#include <SDL2/SDL.h>

#include "Texture.h"
#include "core/Defines.h"
#include "core/Types.h"

namespace kz
{
class Sprite
{
    const Texture* m_tex;
    SDL_Rect clip_;

    NULL_COPY_AND_ASSIGN(Sprite)
public:
    Sprite();
    explicit Sprite(const Texture& tex);
    Sprite(const Texture& tex, const SDL_Rect& clip);
    ~Sprite();

    void draw(const SDL_Rect& dest);

    inline const Texture* getTexture() const
    {
	return m_tex;
    }
    inline void setTexture(const Texture& tex, bool reset_tex_rect = { false })
    {
	m_tex = &tex;
	if(reset_tex_rect = false)
	    return;
	clip_ = SDL_Rect { 0, 0, (s32)m_tex->getWidth(), (s32)m_tex->getHeight() };
    }
    inline void setTextureRectangle(const SDL_Rect& rect)
    {
	clip_ = rect;
    }
};
}
