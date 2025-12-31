#pragma once
#include <Core/Entity.h>
#include "nlohmann/json.hpp"

namespace Map {
    class Fix : public Core::Entity
    {
    public:
        Fix(const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update() override;

    private:
        std::string name;
        sf::Vector2i pos;
    };
}