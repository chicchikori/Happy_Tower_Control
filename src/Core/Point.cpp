#include "Point.h"
#include "SFML/System/Vector2.hpp"

namespace Game
{
    Point::Point(App::Game& game) : Core::Entity(game)
    {
    }

    void Point::SetPoint(sf::Vector2i position)
    {
        this->position = position;
    }

    sf::Vector2i Point::GetPoint()
    {
        return position;
    }
} // namespace Game
