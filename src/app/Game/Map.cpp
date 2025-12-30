#include "Map.h"
#include <filesystem>
#include "MapInfo.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace App
{
    Map::Map(const std::filesystem::path& path) : mapInfo(path)
    {
    }


    void Map::Update()
    {
    }

    void Map::Render(sf::RenderWindow& window)
    {
    }
} // namespace App
