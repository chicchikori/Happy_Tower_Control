#pragma once
#include <SFML/Graphics.hpp>
#include "../app/Game/Game.h"
#include "SFML/Graphics/RenderWindow.hpp"
namespace App
{
    class Game;
}
namespace Core
{
    class Scene
    {
    public:
        Scene(App::Game& game);
        virtual ~Scene() = default;

        virtual void SceneRender(sf::RenderWindow& window) = 0;

        virtual void SceneUpdate() = 0;

        virtual void SceneEvent(sf::Event& event) = 0;

    protected:
        App::Game& game; // NOLINT
    };
} // namespace Core
