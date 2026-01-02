#include "Plane.h"
#include <cmath>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


namespace Game
{
    Plane::Plane(App::Game& game, int speed, int targetSpeed, int heading, int targetHeading, int altitude,
                 int targetAltitude, sf::Vector2f position) :
        Core::Entity(game), speed((float)speed), targetSpeed((float)targetSpeed), heading(sf::degrees((float)heading)),
        targetHeading(sf::degrees((float)targetHeading)), altitude((float)altitude),
        targetAltitude((float)targetAltitude), position(position)
    {
        plane.setSize({4, 4});
        plane.setFillColor(sf::Color::Transparent);
        plane.setOutlineColor(sf::Color::Green);
        plane.setOutlineThickness(2);
    }

    void Plane::Event(sf::Event& event)
    {
    }

    void Plane::Update(float delta)
    {
        position +=
            sf::Vector2f(std::sin(heading.asRadians()), std::cos(heading.asRadians())) * delta * speed * 0.5144444444444444444444444F;
        plane.setPosition(WorldToWindow((sf::Vector2i)position));
    }

    void Plane::Render(sf::RenderWindow& window)
    {
        window.draw(plane);
    }
} // namespace Game
