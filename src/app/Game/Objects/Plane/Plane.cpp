#include "Plane.h"
#include "PlaneHandler.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/Mouse.hpp"

#define PLANE_RECT_OUTLINE_THICKNESS (2)
#define PLANE_RECT_SIZE (sf::Vector2f(4, 4))


namespace Game
{
    sf::Vector2f Plane::planeRectOutlineThickness(4, 4);
    float Plane::planeRectSize(2);

    Plane::Plane(App::Game& game, int speed, int heading, int altitude, sf::Vector2f position) :
        Core::Entity(game), data(game, speed, heading, altitude, position)
    {
        planeShape.setSize(planeRectOutlineThickness);
        planeShape.setFillColor(sf::Color::Transparent);
        planeShape.setOutlineColor(sf::Color::Green);
        planeShape.setOutlineThickness(planeRectSize);
    }

    void Plane::Event(sf::Event& event)
    {
        if (const auto mouseEvent = event.getIf<sf::Event::MouseButtonPressed>())
        {
            if (mouseEvent->button == sf::Mouse::Button::Left)
            {
                MouseLeftReleased(mouseEvent);
            }
        }
    }

    void Plane::MouseLeftReleased(const sf::Event::MouseButtonPressed* mouseEvent)
    {
        sf::Vector2f mouseWorldPos = mGame.GetWindow().mapPixelToCoords(mouseEvent->position);
        if (planeShape.getGlobalBounds().contains(mouseWorldPos))
        {
            if (PlaneHandler::selectedPlaneChanged)
            {
                return;
            }
            if (PlaneHandler::selectedTempPlane != this)
            {
                PlaneHandler::selectedTempPlane = this;
                PlaneHandler::selectedPlaneChanged = true;
            }
            else
            {
                PlaneHandler::selectedTempPlane = nullptr;
            }
        }
    }

    void Plane::Update(float delta)
    {
        if (PlaneHandler::selectedPlane == this)
        {
            planeShape.setOutlineColor(sf::Color::Red);
        }
        else
        {
            planeShape.setOutlineColor(sf::Color::Green);
        }
        data.Update(delta);
        planeShape.setPosition(Round(WorldToWindow((sf::Vector2i)data.GetPosition())));
    }

    void Plane::Render(sf::RenderWindow& window)
    {
        window.draw(planeShape);
    }


} // namespace Game
