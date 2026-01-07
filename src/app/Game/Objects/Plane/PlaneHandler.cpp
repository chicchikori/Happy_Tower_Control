#include "PlaneHandler.h"
#include <cstddef>
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
namespace Game
{
    Plane* PlaneHandler::selectedTempPlane;
    Plane* PlaneHandler::selectedPlane;
    bool PlaneHandler::selectedPlaneChanged(false);

    PlaneHandler::PlaneHandler(App::Game& game) : Core::Entity(game)
    {
        planes.emplace_back(game, 140, 90, 1000, sf::Vector2f(0, 0));
        planes.emplace_back(game, 140, 90, 1000, sf::Vector2f(0, 1000));
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
        selectedPlaneChanged = false;
        for (auto& plane : planes)
        {
            plane.Event(event);
        }

        if (event.is<sf::Event::MouseButtonPressed>() && !selectedPlaneChanged)
        {
            selectedTempPlane = nullptr;
        }
        selectedPlane = selectedTempPlane;
    }
    void PlaneHandler::Render(sf::RenderWindow& window)
    {
        for (std::size_t i = 0; i < planes.size(); i++)
        {
            planes[planes.size() - 1 - i].Render(window);
        }
    }
} // namespace Game
