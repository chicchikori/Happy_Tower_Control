#include "PlaneHandler.h"
#include "SFML/System/Vector2.hpp"
namespace Game
{
    PlaneHandler::PlaneHandler(App::Game& game) : Core::Entity(game)
    {
        planes.emplace_back(game, 140, 140, 90, 90, 1000, 1000, sf::Vector2f(0, 0));
    }

    void PlaneHandler::Update(float delta)
    {
        for (auto& plane : planes)
        {
            plane.Update(delta);
        }
    }
    void PlaneHandler::Event(sf::Event& event)
    {
        for (auto& plane : planes)
        {
            plane.Event(event);
        }
    }
    void PlaneHandler::Render(sf::RenderWindow& window)
    {
        for (auto& plane : planes)
        {
            plane.Render(window);
        }
    }
} // namespace Game
