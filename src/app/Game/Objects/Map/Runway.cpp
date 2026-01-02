
#include "Runway.h"
#include <cmath>
#include <memory>
#include <string>
#include <utility>
#include "SFML/Graphics/Color.hpp"
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"
namespace Map
{
    Runway::Runway(App::Game& game, const nlohmann::basic_json<>& json) :
        Game::Point(game), equipedILS(json["ILSEquiped"].get<bool>())
    {
        name = json["name"].get<std::string>();
        thresholdPos = {json["thresholdPosition"]["x"].get<int>(), json["thresholdPosition"]["y"].get<int>()};
        oppositeThresholdPos = {json["oppositeThresholdPosition"]["x"].get<int>(),
                                json["oppositeThresholdPosition"]["y"].get<int>()};

        heading = (((sf::Vector2f)oppositeThresholdPos - (sf::Vector2f)thresholdPos)).angle();
        length = (int)((sf::Vector2f)oppositeThresholdPos - (sf::Vector2f)thresholdPos).length();

        runwayRad = {sinf(heading.asRadians()), sinf(heading.asRadians())};


        runwayRect.setOrigin({0, 2});
        runwayRect.setRotation(heading);
        runwayRect.setFillColor(sf::Color::White);
    }

    /* void Runway::SetOpposite(std::unique_ptr<Runway> oppositeRunway)
    {
        this->oppositeRunway = std::move(oppositeRunway);
    }*/

    std::string& Runway::GetName()
    {
        return name;
    } 

    void Runway::Render(sf::RenderWindow& window)
    {
        window.draw(runwayRect);
    };
    void Runway::Update(float /*delta*/)
    {
        auto screenLength = WorldToWindow((float)length);
        runwayRect.setSize({screenLength, 4});
        runwayRect.setPosition(WorldToWindow(thresholdPos));
    };


} // namespace Map
