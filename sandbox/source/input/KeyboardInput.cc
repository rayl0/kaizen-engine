#include "KeyboardInput.h"

namespace kz {
const u8* KeyboardInput::m_keyStates = nullptr;

void KeyboardInput::initKeyStates()
{
    m_keyStates = SDL_GetKeyboardState(nullptr);
}
bool KeyboardInput::getKeyDown(SDL_Keycode key)
{
    return m_keyStates[SDL_GetScancodeFromKey(key)];
}
bool KeyboardInput::getKeyUp(SDL_Keycode key)
{
    return m_keyStates[SDL_GetScancodeFromKey(key)];
}
}
