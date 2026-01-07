#include "PlayScene.h"

namespace App
{
    PlayScene::PlayScene(Game& game) : Core::Scene(game), map(game)
    {
    }

    void PlayScene::SceneEvent(sf::Event& event)
    {
    };

    void PlayScene::SceneUpdate()
    {
        float dt = clock.restart().asSeconds();
        map.Update(dt);
    };

    void PlayScene::SceneRender(sf::RenderWindow& window)
    {
        window.clear();
        map.Render(window);
        window.display();
    };

} // namespace App
