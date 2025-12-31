#include "Spawn.h"

namespace Map
{
    void Spawn::Render(sf::RenderWindow& window) {};
    void Spawn::Update() {};
    Spawn::Spawn(const nlohmann::basic_json<>& json) :
        maxAlt(json["maxAlt"].get<int>()), minAlt(json["minAlt"].get<int>()), maxSpeed(json["maxSpeed"].get<int>()),
        minSpeed(json["minSpeed"].get<int>())
    {
        pos = {json["position"]["x"].get<int>(), json["position"]["y"].get<int>()};
        heading = sf::degrees(json["heading"].get<float>());
        headingVariant = sf::degrees(json["headingVariant"].get<float>());
    }

} // namespace Map
