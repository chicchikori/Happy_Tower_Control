#include "Scene.h"
namespace Core
{
    Scene::Scene(App::Game& game) : game(game)
    {
    }

    void Scene::SceneRender(sf::RenderWindow& window)
    {
        window.clear();
        window.display();
    };

    void Scene::SceneUpdate() {};

    void Scene::SceneEvent(sf::Event& event) {};

} // namespace Core
