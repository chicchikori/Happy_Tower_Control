#include "Entity.h"
#include <cmath>
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"


namespace Core
{
    float Entity::zoom = 100;
    sf::Vector2f Entity::offset(0, 0);

    Entity::Entity(App::Game& game) : mGame(game)
    {
    }

    void Entity::Update(float delta) {

    };

    void Entity::Event(sf::Event& event)
    {
    }

    void Entity::Render(sf::RenderWindow& window)
    {
    }

    sf::Vector2f Entity::WorldToWindow(sf::Vector2i worldPos)
    {
        worldPos.y *= -1;
        return ((sf::Vector2f)(worldPos) / zoom + offset + (sf::Vector2f)mGame.GetWindowSize() * 0.5F);
    }

    float Entity::WorldToWindow(const float& length)
    {
        return length / zoom;
    }

    sf::Vector2f Entity::Round(const sf::Vector2f& vec)
    {
        return {roundf(vec.x), roundf(vec.y)};
    }

} // namespace Core
