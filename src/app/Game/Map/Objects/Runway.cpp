
#include "Runway.h"
namespace Map
{
    void Runway::Render(sf::RenderWindow& window) {};
    void Runway::Update() {};
    Runway::Runway(const nlohmann::basic_json<>& json) :
        length(json["length"].get<int>()), equipedILS(json["ILSEquiped"].get<bool>())
    {
        name = json["name"].get<std::string>();
        heading = sf::degrees(json["heading"].get<float>());
        thresholdPos = {json["thresholdPosition"]["x"].get<int>(), json["thresholdPosition"]["y"].get<int>()};
    }

} // namespace Map
