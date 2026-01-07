#pragma once
#include <Core/Entity.h>
#include <Core/Point.h>
#include <memory>
#include <string>
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"
#include "nlohmann/json.hpp"

namespace Map
{
    class Runway : public Game::Point
    {
    public:
        Runway(App::Game& game, const nlohmann::basic_json<>& json);
        Runway(App::Game& game, std::string name, sf::Vector2i thresholdPos, bool equipedILS);
        // void SetOpposite(std::unique_ptr<Runway> oppositeRunway);
        std::string& GetName();
        void Render(sf::RenderWindow& window) override;
        void Update(float delta) override;
        ~Runway() override = default;


    private:
        std::string name;
        sf::Angle heading;
        sf::Vector2i thresholdPos;
        sf::Vector2i oppositeThresholdPos;
        sf::Angle oppositeHeading;
        sf::RectangleShape runwayRect;
        // std::unique_ptr<Runway> oppositeRunway;

        sf::Vector2f runwayRad;

        int length;
        bool equipedILS;
    };
} // namespace Map
