#pragma once

#include <Core/Entity.h>
#include "nlohmann/json.hpp"

namespace Map {
    class Airspace : public Core::Entity
    {
    public:
        Airspace(const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update() override;

    private:
        std::vector<sf::Vector2i> airspace;
    };
}