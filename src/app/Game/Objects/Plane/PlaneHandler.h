#pragma once
#include <Core/Entity.h>
#include <vector>
#include "Plane.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Window/Event.hpp"


namespace Game
{
    class PlaneHandler : public Core::Entity
    {
    public:
        PlaneHandler(App::Game& game);
        void Update(float delta) override;
        void Event(sf::Event& event) override;
        void Render(sf::RenderWindow& window) override;

        static Plane* selectedPlane;
        static Plane* selectedTempPlane;
        static bool selectedPlaneChanged;

    private:
        std::vector<Plane> planes;
    };
} // namespace Game
