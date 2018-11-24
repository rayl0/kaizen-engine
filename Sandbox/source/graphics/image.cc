#include "image.h"

#include <SDL2/SDL_image.h>

namespace kz {
Image::Image()
    : surf_(nullptr),
    width_(0),
    height_(0)
{
}
Image::Image(const std::string& file)
    : surf_(nullptr)
{
    Load(file);
}
Image::~Image()
{
    Free();
}

void Image::Load(const std::string& file)
{
    surf_ = IMG_Load(file.c_str());
    width_ = surf_->w;
    height_ = surf_->h;
}

void Image::Free()
{
    SDL_FreeSurface(surf_);
}
}
