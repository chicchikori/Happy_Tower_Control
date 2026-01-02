#include "FontManager.h"
#include <string>
#include <utility>
#include "SFML/Graphics/Font.hpp"

#define FONT_DIRCTORY ("Assets/Fonts/")
std::unordered_map<std::string, sf::Font> FontManager::fonts;
sf::Font& FontManager::Get(const std::string& name)
{
    if (!fonts.contains(name))
    {
        fonts.emplace(std::pair<std::string, sf::Font>(name, sf::Font(FONT_DIRCTORY + name)));
    }
    return fonts[name];
};
