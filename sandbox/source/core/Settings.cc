#include "Settings.h"

#include <fstream>
#include <iostream>

namespace kz
{
Settings::Settings(const std::string& file)
{
    load(file);
}

Settings::~Settings()
{
}

void Settings::load(const std::string& file)
{
    std::ifstream settingsFile(file);
    if(!settingsFile.is_open()) {
	// std::cerr << "not open" << std::endl;
	return;
    }
    settingsFile.seekg(0, std::ios::end);
    s32 length = settingsFile.tellg();
    settingsFile.seekg(0, std::ios::beg);

    char buffer[length];
    buffer[length] = '\0';
    settingsFile.read(buffer, length);
    m_settingsObject = json::parse(buffer);

    m_windowSettings.title = m_settingsObject["window"]["title"].get<std::string>();
    m_windowSettings.width = m_settingsObject["window"]["width"].get<s32>();
    m_windowSettings.height = m_settingsObject["window"]["height"].get<s32>();
}
}
