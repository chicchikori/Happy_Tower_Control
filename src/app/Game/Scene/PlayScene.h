#pragma once
#include <Core/Scene.h>
#include "../Map/Map.h"
#include "SFML/Window/Event.hpp"
#include "../Objects/Plane/PlaneHandler.h"


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
        sf::Clock clock;
        Map::Map map;
        ::Game::PlaneHandler planeHandler;
    };
} // namespace App
