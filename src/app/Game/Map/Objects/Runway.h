#pragma once
#include <Core/Entity.h>
#include "nlohmann/json.hpp"
namespace Map
{
    class Runway : public Core::Entity
    {
    public:
        Runway(const nlohmann::basic_json<>& json);
        void Render(sf::RenderWindow& window) override;
        void Update() override;


    private:
        std::string name;
        sf::Angle heading;
        sf::Vector2i thresholdPos;
        int length;
        bool equipedILS;
    };
} // namespace Map
