#include "Fix.h"
namespace Map
{
    void Fix::Render(sf::RenderWindow& window) {};
    void Fix::Update() {};
    Map::Fix::Fix(const nlohmann::basic_json<>& json)
    {
        name = json["name"].get<std::string>();
        pos = {json["position"]["x"].get<int>(), json["position"]["y"].get<int>()};
    }

} // namespace Map
