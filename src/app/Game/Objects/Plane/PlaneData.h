#pragma once
#include <Core/Entity.h>
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

namespace Game
{
    class PlaneData : public Core::Entity
    {
    public:
        PlaneData(App::Game& game, int speed, int heading, int altitude, sf::Vector2f position);
        void Event(sf::Event& event) override;
        void Update(float delta) override;
        void Render(sf::RenderWindow& window) override;


        void SetSpeed(int speed);
        void Setheading(int heading);
        void SetAltitude(int altitude);

        sf::Vector2f GetPosition();

    private:
        // board
        sf::Vector2i offset;
        sf::VertexArray lines;

        sf::RectangleShape board;
        sf::Text line1;
        sf::Text line2;
        sf::Text line3;
        sf::Text line4;
        sf::Text line5;


        // data
        std::string callsign;

        float speed;
        float targetSpeed;
        float speedChangeDelta;
        float speedSaturaion{4.F};
        void UpdateSpeed(float delta);

        sf::Angle heading;
        sf::Angle targetHeading;
        sf::Angle headingChangeDelta{sf::degrees(1)};
        float headingSaturation{5.F};
        void UpdateHeading(float delta);

        float altitude;
        float targetAltitude;
        float altitudeChangeDelta;
        float altitudeSaturasion{200.F};
        void UpdateAltitude(float delta);

        sf::Vector2f position;
        void UpdatePosition(float delta);
    };
} // namespace Game
