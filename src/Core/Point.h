#pragma once

#include "SFML/System/Vector2.hpp"

#include <Core/Entity.h>

namespace Game
{
    class Point : public Core::Entity
    {
    public:
        Point(App::Game& game);
        sf::Vector2i GetPoint();

    protected:
        void SetPoint(sf::Vector2i position);

    private:
        sf::Vector2i position;
    };

} // namespace Game
