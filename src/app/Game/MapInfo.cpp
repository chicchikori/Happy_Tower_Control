#pragma once

#include "MapInfo.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include "SFML/System/Angle.hpp"
#include "SFML/System/Vector2.hpp"


MapInfo::MapInfo(const std::filesystem::path& path)
{
    Load(path);
};

void MapInfo::Load(const std::filesystem::path& path)
{
    std::ifstream ifst(path);
    auto json = nlohmann::json::parse(ifst);

    // get airport info
    airport.name = json["airports"]["name"].get<std::string>();
    airport.pos = {json["airports"]["position"]["x"].get<int>(), json["airports"]["position"]["y"].get<int>()};

    // get runways
    for (const auto& rwy : json["airports"]["runways"])
    {
        Runway tempRwy;
        tempRwy.name = rwy["name"].get<std::string>();
        tempRwy.heading = sf::degrees(rwy["heading"].get<float>());
        tempRwy.thresholdPos = {rwy["thresholdPosition"]["x"].get<int>(), rwy["thresholdPosition"]["y"].get<int>()};
        tempRwy.length = rwy["length"].get<int>();
        tempRwy.equipedILS = rwy["ILSEquiped"].get<bool>();
        airport.runways.push_back(tempRwy);
    }

    // get fixes

    for (const auto& fix : json["fixes"])
    {
        Fix tempFix;
        tempFix.name = fix["name"].get<std::string>();
        tempFix.pos = {fix["position"]["x"].get<int>(), fix["position"]["y"].get<int>()};
        fixes.push_back(tempFix);
    }

    // get airspace
    for (const auto& airspace : json["airspace"])
    {
    }

    // get spwans
    for (const auto& spawn : json["spawns"])
    {
        Spawn tempSpwan;
        tempSpwan.pos = {spawn["position"]["x"].get<int>(), spawn["position"]["y"].get<int>()};
        tempSpwan.maxAlt = spawn["maxAlt"].get<int>();
        tempSpwan.minAlt = spawn["minAlt"].get<int>();
        tempSpwan.heading = sf::degrees(spawn["heading"].get<float>());
        tempSpwan.headingVariant = sf::degrees(spawn["headingVariant"].get<float>());
        tempSpwan.maxSpeed = spawn["maxSpeed"].get<int>();
        tempSpwan.minSpeed = spawn["minSpeed"].get<int>();

        spawns.push_back(tempSpwan);
    }
    std::cout << "load complete\n";
};
