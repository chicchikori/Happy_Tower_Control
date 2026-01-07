#pragma once
#include <Core/Entity.h>
#include "PlaneData.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Event.hpp"

namespace Game
{
    class Plane : private Core::Entity
    {
    public:
        Plane(App::Game& game, int speed, int heading, int altitude, sf::Vector2f position);
        void Event(sf::Event& event) override;
        void Update(float delta) override;
        void Render(sf::RenderWindow& window) override;

        void SetSpeed(int speed);
        void Setheading(int heading);
        void SetAltitude(int altitude);

    private:
        PlaneData data;
        int planeID;
        
        sf::RectangleShape planeShape;

        void MouseLeftReleased(const sf::Event::MouseButtonPressed* mouseEvent);

        static sf::Vector2f planeRectOutlineThickness;

        static float planeRectSize;
    };
} // namespace Game
