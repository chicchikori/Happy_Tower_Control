#include "PlaneData.h"
#include <Core/FontManager.h>
#include <cmath>
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"


#define KNOT_TO_MPERS (0.5144444444444444444444444F)


namespace Game
{
    PlaneData::PlaneData(App::Game& game, int speed, int heading, int altitude, sf::Vector2f position) :
        Core::Entity(game), line1(FontManager::Get("RobotoR.ttf")), line2(FontManager::Get("RobotoR.ttf")),
        line3(FontManager::Get("RobotoR.ttf")), line4(FontManager::Get("RobotoR.ttf")),
        line5(FontManager::Get("RobotoR.ttf")), speed((float)speed), targetSpeed((float)speed),
        heading(sf::degrees((float)heading)), targetHeading(sf::degrees((float)heading)), altitude((float)altitude),
        targetAltitude((float)altitude), position(position)
    {
        board.setSize({40, 30});
        board.setFillColor(sf::Color::White);
        offset = {100, 100};
    }

    void PlaneData::Event(sf::Event& event)
    {
    }

    void PlaneData::Update(float delta)
    {
        UpdateSpeed(delta);
        UpdateHeading(delta);
        UpdateAltitude(delta);
        UpdatePosition(delta);
    }

    void PlaneData::Render(sf::RenderWindow& window)
    {
        window.draw(board);
    }

    void PlaneData::SetAltitude(int altitude)
    {
        targetAltitude = (float)altitude;
    }

    void PlaneData::Setheading(int heading)
    {
        targetHeading = sf::degrees((float)heading);
    }

    void PlaneData::SetSpeed(int speed)
    {
        targetSpeed = (float)speed;
    }

    sf::Vector2f PlaneData::GetPosition()
    {
        return position;
    }

    void PlaneData::UpdateSpeed(float delta)
    {
        heading +=
            std::clamp((targetHeading - heading).wrapSigned().asDegrees(), -headingSaturation, headingSaturation) /
            headingSaturation * headingChangeDelta * delta;
    }
    void PlaneData::UpdateHeading(float delta)
    {
        altitude += std::clamp(targetAltitude - altitude, -altitudeSaturasion, altitudeSaturasion) /
            altitudeSaturasion * altitudeChangeDelta * delta;
    }
    void PlaneData::UpdateAltitude(float delta)
    {
        speed += std::clamp(targetSpeed - speed, -speedSaturaion, speedSaturaion) / speedSaturaion * speedChangeDelta *
            delta;
    }
    void PlaneData::UpdatePosition(float delta)
    {
        position +=
            sf::Vector2f(std::sin(heading.asRadians()), std::cos(heading.asRadians())) * delta * speed * KNOT_TO_MPERS;
    }
} // namespace Game
