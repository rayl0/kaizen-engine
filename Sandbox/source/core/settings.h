#pragma once

#include <string>

#include <nlohmann/json.hpp>

#include "types.h"

using json = nlohmann::json;

namespace kz {
class Settings {
    json settings_object_;

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
    } window_settings_;

public:
    Settings() {}
    Settings(const std::string& file);
    ~Settings();

    void LoadSettings(const std::string& file);

    inline const WindowSettings& GetWindowSettings() const { return window_settings_; }
};
}
