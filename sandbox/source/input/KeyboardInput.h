#pragma once

#include <SDL2/SDL.h>

#include "core/Types.h"

namespace kz {
class KeyboardInput {
    static const u8* m_keyStates;

    KeyboardInput() {}
    ~KeyboardInput() {}

public:
    static void initKeyStates();
    static bool getKeyDown(SDL_Keycode key);
    static bool getKeyUp(SDL_Keycode key);
};
}
