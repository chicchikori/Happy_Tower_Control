#pragma once

#include <Core/Entity.h>
#include <SFML/System.hpp>
#include <filesystem>
#include <vector>


#include "../Objects/Map/Airport.h"
#include "../Objects/Map/Airspace.h"
#include "../Objects/Map/Fix.h"
#include "../Objects/Map/Runway.h"
#include "../Objects/Map/Spawn.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Map
{
    class Map
    {
    public:
        Map(App::Game& game, const std::filesystem::path& path = "./Assets/Map/Test.json");

        void Render(sf::RenderWindow& window);

        void Update(float delta);

        void Load(App::Game& game, const std::filesystem::path& path);

        [[nodiscard]] std::vector<Airport>& GetAirportInfo();
        [[nodiscard]] std::vector<Spawn>& GetSpawns();
        [[nodiscard]] std::vector<Airspaces>& GetAirspaces();
        [[nodiscard]] std::vector<Fix>& GetFixies();

    private:
        std::vector<Airport> airports;
        std::vector<Spawn> spawns;
        std::vector<Airspaces> airspaces;
        std::vector<Fix> fixes;
        std::vector<Runway> runways;
    };


} // namespace Map
