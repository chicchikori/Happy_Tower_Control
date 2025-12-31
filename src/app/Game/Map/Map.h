#pragma once

#include <Core/Entity.h>
#include <SFML/System.hpp>
#include <filesystem>
#include <vector>



#include "Objects\Airport.h"
#include "Objects\Airspace.h"
#include "Objects\Fix.h"
#include "Objects\Runway.h"
#include "Objects\Spawn.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace Map
{
    class Map
    {
    public:
        Map(const std::filesystem::path& path = "./Assets/Map/Test.json");

        void Render(sf::RenderWindow& window);

        void Update();
        void Load(const std::filesystem::path& path);
        [[nodiscard]] std::vector<Airport>& GetAirportInfo();
        [[nodiscard]] std::vector<Spawn>& GetSpawns();
        [[nodiscard]] std::vector<Airspace>& GetAirspace();
        [[nodiscard]] std::vector<Fix>& GetFixies();

    private:
        std::vector<Airport> airport;
        std::vector<Spawn> spawns;
        std::vector<Airspace> airspaces;
        std::vector<Fix> fixes;
        std::vector<Runway> runways;
    };


} // namespace Map
