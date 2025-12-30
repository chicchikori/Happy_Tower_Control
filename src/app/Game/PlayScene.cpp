#include "PlayScene.h"
#include "Map.h"

namespace App
{
    PlayScene::PlayScene(Game& game) : Core::Scene(game)
    {
    }

    void PlayScene::SceneEvent(sf::Event& event) {

    };

    void PlayScene::SceneUpdate() {

    };

    void PlayScene::SceneRender(sf::RenderWindow& window)
    {
        window.clear();
        map.Render(window);
        window.display();
    };

} // namespace App
