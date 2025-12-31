#include "Airport.h"
namespace Map
{

    Airport::Airport(const nlohmann::basic_json<>& json)
    {
        name = json["name"].get<std::string>();
        pos = {json["position"]["x"].get<int>(), json["position"]["y"].get<int>()};
        for (const auto& runways : json["runways"])
        {
            this->runways.emplace_back(runways);
        }
    }
    void Airport::Render(sf::RenderWindow& window) {};
    void Airport::Update() {};
} // namespace Map
