#include "Image.h"

#include <SDL2/SDL_image.h>

namespace kz {
Image::Image()
    : m_surface(nullptr),
    m_width(0),
    m_height(0)
{
}
Image::Image(const std::string& file)
    : m_surface(nullptr)
{
    load(file);
}
Image::~Image()
{
    free();
}

void Image::load(const std::string& file)
{
    m_surface = IMG_Load(file.c_str());
    m_width = m_surface->w;
    m_height = m_surface->h;
}

void Image::free()
{
    SDL_FreeSurface(m_surface);
}
}
