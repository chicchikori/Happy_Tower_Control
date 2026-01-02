#pragma once

#include <Core/Entity.h>
#include "nlohmann/json.hpp"

#include <Core/Point.h>
namespace Map
{
    class Spawn : public Game::Point
    {
    public:
        Spawn(App::Game& game, const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update(float delta) override;

    private:
        sf::Vector2i pos;
        int maxAlt;
        int minAlt;
        sf::Angle heading;
        sf::Angle headingVariant;
        int maxSpeed;
        int minSpeed;
    };
} // namespace Map
