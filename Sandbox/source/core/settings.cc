#include "settings.h"

#include <fstream>
#include <iostream>

namespace kz {
Settings::Settings(const std::string& file)
{
    LoadSettings(file);
}

Settings::~Settings()
{
}

void Settings::LoadSettings(const std::string& file)
{
    std::ifstream settings_file(file);
    if (!settings_file.is_open())
        std::cerr << "not open" << std::endl;
    settings_file.seekg(0, std::ios::end);
    s32 length = settings_file.tellg();
    settings_file.seekg(0, std::ios::beg);

    char buffer[length];
    buffer[length] = '\0';
    settings_file.read(buffer, length);
    settings_object_ = json::parse(buffer);

    window_settings_.title = settings_object_["window"]["title"].get<std::string>();
    window_settings_.width = settings_object_["window"]["width"].get<s32>();
    window_settings_.height = settings_object_["window"]["height"].get<s32>();
}
}
