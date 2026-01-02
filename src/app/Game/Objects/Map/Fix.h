#pragma once
#include <Core/Entity.h>
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Text.hpp"
#include "nlohmann/json.hpp"

#include <Core/Point.h>
namespace Map
{
    class Fix : public Game::Point
    {
    public:
        Fix(App::Game& game, const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update(float delta) override;

    private:
        sf::Vector2f GetLabelOrigin();

        std::string name;
        sf::Text labal;
        sf::CircleShape triangle{5.F,3};
    };
} // namespace Map
