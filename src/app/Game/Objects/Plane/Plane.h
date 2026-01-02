#pragma once
#include <Core/Entity.h>
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

namespace Game
{
    class Plane : public Core::Entity
    {
    public:
        Plane(App::Game& game, int speed, int targetSpeed, int heading, int targetHeading, int altitude,
              int targetAltitude, sf::Vector2f position);
        void Event(sf::Event& event) override;
        void Update(float delta) override;
        void Render(sf::RenderWindow& window) override;

        void SetSpeed(int speed);
        void Setheading(int heading);
        void SetAltitude(int altitude);

    private:
        float speed;
        float targetSpeed;
        sf::Angle heading;
        sf::Angle targetHeading;
        float altitude;
        float targetAltitude;
            

        sf::Vector2f position;

        sf::RectangleShape plane;
    };
} // namespace Game
