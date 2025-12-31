#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"
namespace Core
{
    class Entity
    {
    public:
        Entity() = default;
        virtual void Event(sf::Event& event);
        virtual void Update();
        virtual void Render(sf::RenderWindow& window);
        virtual ~Entity() = default;

    protected:
        sf::Vector2f WorldToWindow(const sf::Vector2i& worldPos);
    };
} // namespace Core
