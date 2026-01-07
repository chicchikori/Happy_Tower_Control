#pragma once

#include <Core/Entity.h>
#include <Core/Point.h>
#include <string>
#include <unordered_map>
#include "Runway.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "nlohmann/json.hpp"


#define AIRPORT_COLOR sf::Color(0, 255, 0)

namespace Map
{
    class Airport : public Game::Point
    {
    public:
        Airport(App::Game& game);
        Airport(App::Game& game, const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update(float delta) override;

    private:
        std::unordered_map<std::string, Runway> runways;
        std::string name;
        sf::CircleShape airportSign;
        sf::Text airportLabel;

        sf::Vector2f GetLabelOrigin();
    };

} // namespace Map
