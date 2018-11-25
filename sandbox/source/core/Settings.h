#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "Types.h"

using json = nlohmann::json;

namespace kz {
class Settings {
    json m_settingsObject;

    struct WindowSettings {
        WindowSettings()
            : title("")
            , width(0)
            , height(0)
        {
        }

        ~WindowSettings() {}
        std::string title;
        s32 width;
        s32 height;
    } m_windowSettings;

public:
    Settings() {}
    Settings(const std::string& file);
    ~Settings();

    void load(const std::string& file);

    inline const WindowSettings& getWindowSettings() const { return m_windowSettings; }
};
}
