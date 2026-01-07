#include "Airspace.h"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/System/Vector2.hpp"
namespace Map
{
    Airspaces::Airspaces(App::Game& game, const nlohmann::basic_json<>& json) : Core::Entity(game)
    {
        // TODO get airspace's infos
        for (const auto& space : json["space"])
        {
            airspaceInW.emplace_back(space["x"].get<int>(), space["y"].get<int>());
        }
        airspaceShape.resize(airspaceInW.size() + 1);
        airspaceShape.setPrimitiveType(sf::PrimitiveType::LineStrip);
    }

    void Airspaces::Render(sf::RenderWindow& window)
    {
        window.draw(airspaceShape);
    };

    void Airspaces::Update(float /*delta*/)
    {
        for (int i = 0; i < airspaceInW.size(); i++)
        {
            airspaceShape[i].position = Round(WorldToWindow(airspaceInW[i]));
            airspaceShape[i].color = sf::Color::White;
        }
        airspaceShape[airspaceInW.size()].position = Round(WorldToWindow(airspaceInW[0]));
        airspaceShape[airspaceInW.size()].color = sf::Color::White;
    };

} // namespace Map
