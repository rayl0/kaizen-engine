#include "keyboardinput.h"

namespace kz {
const u8* KeyboardInput::keyboard_state_ = nullptr;

void KeyboardInput::InitKeyboard()
{
    keyboard_state_ = SDL_GetKeyboardState(nullptr);
}
bool KeyboardInput::GetKeyDown(SDL_Keycode key)
{
    return keyboard_state_[SDL_GetScancodeFromKey(key)];
}
bool KeyboardInput::GetKeyUp(SDL_Keycode key)
{
    return keyboard_state_[SDL_GetScancodeFromKey(key)];
}
}
