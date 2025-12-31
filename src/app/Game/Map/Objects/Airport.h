#pragma once

#include <Core/Entity.h>
#include <vector>
#include "Runway.h"
#include "nlohmann/json.hpp"


namespace Map
{

    class Airport : public Core::Entity
    {
    public:
        Airport() = default;
        Airport(const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override ;
        void Update() override ;

    private:
        std::vector<Runway> runways;
        std::string name;
        sf::Vector2i pos;
    };

} // namespace Map
