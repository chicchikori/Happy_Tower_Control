#pragma once

#include <string>
#include "SFML/Graphics/Font.hpp"
class FontManager
{
public:
    static sf::Font& Get(const std::string& name);

private:
    static std::unordered_map<std::string, sf::Font> fonts;
};
