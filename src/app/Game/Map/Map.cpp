#include "Map.h"
#include <filesystem>
#include <fstream>
#include <iostream>
#include "SFML/Graphics/RenderWindow.hpp"


namespace Map
{
    Map::Map(App::Game& game, const std::filesystem::path& path)
    {
        Load(game, path);
    }


    void Map::Update(float delta)
    {
        for (auto& airportsF : airports)
        {
            airportsF.Update(delta);
        }
        for (auto& spawnsF : spawns)
        {
            spawnsF.Update(delta);
        }
        for (auto& airspacesF : airspaces)
        {
            airspacesF.Update(delta);
        }
        for (auto& fixesF : fixes)
        {
            fixesF.Update(delta);
        }
        for (auto& runwaysF : runways)
        {
            runwaysF.Update(delta);
        }
    }

    void Map::Render(sf::RenderWindow& window)
    {
        for (auto& airportsF : airports)
        {
            airportsF.Render(window);
        }
        for (auto& spawnsF : spawns)
        {
            spawnsF.Render(window);
        }
        for (auto& airspacesF : airspaces)
        {
            airspacesF.Render(window);
        }
        for (auto& fixesF : fixes)
        {
            fixesF.Render(window);
        }
        for (auto& runwaysF : runways)
        {
            runwaysF.Render(window);
        }
    }

    void Map::Load(App::Game& game, const std::filesystem::path& path)
    {
        std::ifstream ifst(path);
        auto json = nlohmann::json::parse(ifst);

        // get airport info
        for (const auto& airportsJson : json["airports"])
        {
            airports.emplace_back(game, airportsJson);
        }
        // get runways


        // get fixes
        for (const auto& fixJson : json["fixes"])
        {
            fixes.emplace_back(game, fixJson);
        }

        // get airspace
        for (const auto& airspaceJson : json["airspace"])
        {
            airspaces.emplace_back(game, airspaceJson);
        }

        // get spwans
        for (const auto& spawnsJson : json["spawns"])
        {
            spawns.emplace_back(game, spawnsJson);
        }

        std::cout << "load complete\n";
    };
    std::vector<Airport>& Map::GetAirportInfo()
    {
        return airports;
    };
    std::vector<Spawn>& Map::GetSpawns()
    {
        return spawns;
    };
    std::vector<Airspaces>& Map::GetAirspaces()
    {
        return airspaces;
    };
    std::vector<Fix>& Map::GetFixies()
    {
        return fixes;
    };
} // namespace Map
