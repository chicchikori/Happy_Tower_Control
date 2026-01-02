#include "Airport.h"
#include <Core/FontManager.h>
#include "Runway.h"
#include "SFML/System/Vector2.hpp"


namespace Map
{

    Airport::Airport(App::Game& game, const nlohmann::basic_json<>& json) :
        Game::Point(game), name(json["name"].get<std::string>()),
        airportLabel(FontManager::Get("RobotoR.ttf"), name, 10)
    {
        SetPoint({json["position"]["x"].get<int>(), json["position"]["y"].get<int>()});
        for (const auto& runways : json["runways"])
        {
            Runway rwy(game, runways);

            this->runways.try_emplace(rwy.GetName(), rwy);
        }
        airportSign.setRadius(2);
        airportSign.setOrigin({1, 1});
        airportSign.setFillColor(AIRPORT_COLOR);

        airportLabel.setOrigin(Round(GetLabelOrigin()));
    }

    void Airport::Render(sf::RenderWindow& window)
    {
        window.draw(airportSign);
        window.draw(airportLabel);
        for (auto& runway : runways)
        {
            runway.second.Render(window);
        }
    };

    void Airport::Update(float delta)
    {
        auto worldPos = WorldToWindow(GetPoint());
        airportSign.setPosition(worldPos);
        airportLabel.setPosition(worldPos);
        for (auto& runway : runways)
        {
            runway.second.Update(delta);
        }
    };

    sf::Vector2f Airport::GetLabelOrigin()
    {
        return {airportLabel.getGlobalBounds().size.x * .5F, airportLabel.getGlobalBounds().size.y + 8};
    }

} // namespace Map
