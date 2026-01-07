#pragma once

#include <Core/Entity.h>
#include <Core/Point.h>
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include "SFML/System/Vector2.hpp"
#include "nlohmann/json.hpp"


namespace Map
{
    class Airspaces : public Core::Entity
    {
    public:
        Airspaces(App::Game& game, const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update(float delta) override;

    private:
        std::vector<sf::Vector2i> airspaceInW;
        sf::VertexArray airspaceShape{sf::PrimitiveType::LineStrip};
    };
} // namespace Map
