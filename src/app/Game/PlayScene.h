#pragma once
#include "../../Core/Scene.h"
#include "Map.h"
#include "SFML/Window/Event.hpp"
namespace App
{
    class PlayScene : public Core::Scene
    {
    public:
        PlayScene(Game& game);

        void SceneRender(sf::RenderWindow& window) override;

        void SceneUpdate() override;

        void SceneEvent(sf::Event& event) override;

        ~PlayScene() override = default;

    private:
        Map map;
    };
} // namespace App
