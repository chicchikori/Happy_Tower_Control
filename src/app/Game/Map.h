#pragma once

#include <filesystem>
#include "MapInfo.h"
#include "SFML/Graphics/RenderWindow.hpp"
namespace App
{
    class Map
    {
    public:
        Map(const std::filesystem::path& path = "./Assets/Map/Test.json");

        void Render(sf::RenderWindow& window);

        void Update();

    private:
        void LoadMap(const std::filesystem::path& path);
        MapInfo mapInfo;
    };


} // namespace App
