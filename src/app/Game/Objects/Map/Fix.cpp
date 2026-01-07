#include "Fix.h"
#include <Core/FontManager.h>
#include "SFML/Graphics/Color.hpp"
namespace Map
{
    Map::Fix::Fix(App::Game& game, const nlohmann::basic_json<>& json) :
        Game::Point(game), name(json["name"].get<std::string>()), labal(FontManager::Get("RobotoR.ttf"), name, 10)
    {
        SetPoint({json["position"]["x"].get<int>(), json["position"]["y"].get<int>()});

        triangle.setFillColor(sf::Color::Blue);
        triangle.setOrigin(Round(triangle.getGlobalBounds().size * .5F));

        labal.setOrigin(Round(GetLabelOrigin()));
        labal.setFillColor(sf::Color::White);
    }
    void Fix::Render(sf::RenderWindow& window)
    {
        window.draw(triangle);
        window.draw(labal);
    };
    void Fix::Update(float /*delta*/)
    {
        auto windowPos = WorldToWindow(GetPoint());
        triangle.setPosition(windowPos);
        labal.setPosition(windowPos);
    };
    sf::Vector2f Fix::GetLabelOrigin()
    {
        return {labal.getGlobalBounds().size.x * .5F, labal.getGlobalBounds().size.y + 8};
    }

} // namespace Map
