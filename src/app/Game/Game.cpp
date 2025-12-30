#include "Game.h"
#include <memory>
#include <utility>
#include "../../Core/Scene.h"

#include "PlayScene.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/Window/VideoMode.hpp"
namespace App
{
    Game::Game()
    {
        window = sf::RenderWindow(sf::VideoMode({1000, 800}), "test");
        currentScene = std::make_unique<PlayScene>(PlayScene(*this));
    }

    void Game::Run()
    {
        while (isRunning)
        {
            Event();
            Update();
            Render();
        }
    }

    void Game::SetCurrentScene(std::unique_ptr<Core::Scene> scene)
    {
        currentScene = std::move(scene);
    }

    void Game::Event()
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                isRunning = false;
            }
            currentScene->SceneEvent(*event);
        }
    }

    void Game::Update()
    {
        currentScene->SceneUpdate();
    }

    void Game::Render()
    {
        currentScene->SceneRender(window);
    }
}; // namespace App
