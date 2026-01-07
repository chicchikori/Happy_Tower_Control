#pragma once

#include "../app/Game/Game.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

namespace Core
{
    class Entity
    {
    public:
        Entity(App::Game& mGame);
        virtual void Event(sf::Event& event);
        virtual void Update(float delta);
        virtual void Render(sf::RenderWindow& window);
        virtual ~Entity() = default;

        static sf::Vector2f Round(const sf::Vector2f& vec);

    protected:
        sf::Vector2f WorldToWindow(sf::Vector2i worldPos);
        static float WorldToWindow(const float& length);
        App::Game& mGame;

    private:
        static float zoom;
        static sf::Vector2f offset;
    };
} // namespace Core
