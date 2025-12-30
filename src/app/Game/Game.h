#pragma once

#include <memory>
#include "../../Core/Scene.h"
#include "SFML/Graphics/RenderWindow.hpp"
namespace Core
{
    class Scene;
}
namespace App
{
    class Game
    {
    public:
        Game();
        void Run();

        void SetCurrentScene(std::unique_ptr<Core::Scene> scene);

    private:
        sf::RenderWindow window;

        std::unique_ptr<Core::Scene> currentScene;

        void Update();
        void Event();
        void Render();

        bool isRunning{true};
    };
} // namespace App
