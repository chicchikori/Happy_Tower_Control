#include "Airspace.h"
#include <iostream>
namespace Map
{

    Airspace::Airspace(const nlohmann::basic_json<>& json)
    {
        // TODO get airspace's infos

        std::cout << json["type"].get<std::string>() << "\n";
    }
    void Airspace::Render(sf::RenderWindow& window) {};
    void Airspace::Update() {};

} // namespace Map
