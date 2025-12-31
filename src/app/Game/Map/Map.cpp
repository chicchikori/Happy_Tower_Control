#include "Map.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "SFML/Graphics/RenderWindow.hpp"


namespace Map
{
    Map::Map(const std::filesystem::path& path)
    {
        Load(path);
    }


    void Map::Update()
    {
    }

    void Map::Render(sf::RenderWindow& window)
    {
    }

    void Map::Load(const std::filesystem::path& path)
    {
        std::ifstream ifst(path);
        auto json = nlohmann::json::parse(ifst);

        // get airport info
        for (const auto& airportsJson : json["airports"])
        {
            airport.emplace_back(airportsJson);
        }
        // get runways


        // get fixes
        for (const auto& fixJson : json["fixes"])
        {
            fixes.emplace_back(fixJson);
        }

        // get airspace
        for (const auto& airspaceJson : json["airspace"])
        {
            airspaces.emplace_back(airspaceJson);
        }

        // get spwans
        for (const auto& spawnsJson : json["spawns"])
        {
            spawns.emplace_back(spawnsJson);
        }

        std::cout << "load complete\n";
    };
    std::vector<Airport>& Map::GetAirportInfo()
    {
        return airport;
    };
    std::vector<Spawn>& Map::GetSpawns()
    {
        return spawns;
    };
    std::vector<Airspace>& Map::GetAirspace()
    {
        return airspaces;
    };
    std::vector<Fix>& Map::GetFixies()
    {
        return fixes;
    };
} // namespace Map
