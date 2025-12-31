#pragma once

#include <Core/Entity.h>
#include "nlohmann/json.hpp"

namespace Map {
    class Spawn : public Core::Entity
    {
    public:
        Spawn(const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update() override;

    private:
        sf::Vector2i pos;
        int maxAlt;
        int minAlt;
        sf::Angle heading;
        sf::Angle headingVariant;
        int maxSpeed;
        int minSpeed;
    };
}