#include "PlayScene.h"

namespace App
{
    PlayScene::PlayScene(Game& game) : Core::Scene(game), map(game), planeHandler(game)
    {
    }

    void PlayScene::SceneEvent(sf::Event& event)
    {
        planeHandler.Event(event);
    };

    void PlayScene::SceneUpdate()
    {
        float dt = clock.restart().asSeconds();
        map.Update(dt);
        planeHandler.Update(dt);
    };

    void PlayScene::SceneRender(sf::RenderWindow& window)
    {
        window.clear();
        map.Render(window);
        planeHandler.Render(window);
        window.display();
    };

} // namespace App
