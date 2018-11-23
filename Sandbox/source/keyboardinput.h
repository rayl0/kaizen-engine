#pragma once

#include <SDL2/SDL.h>

#include "types.h"

namespace kz {
class KeyboardInput {
    static const u8* keyboard_state_;

    KeyboardInput() {}
    ~KeyboardInput() {}

public:
    static void InitKeyboard();
    static bool GetKeyDown(SDL_Keycode key);
    static bool GetKeyUp(SDL_Keycode key);
};
}
