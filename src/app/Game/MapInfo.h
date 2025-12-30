#pragma once

#include <SFML/System.hpp>
#include <filesystem>
#include <string>
#include <vector>
#include "SFML/System/Vector2.hpp"


class MapInfo
{
    struct Runway
    {
        std::string name;
        sf::Angle heading;
        sf::Vector2i thresholdPos;
        int length;
        bool equipedILS;
    };

    struct Airspace
    {
        std::vector<sf::Vector2i> airspace;
    };

    struct Spawn
    {
        sf::Vector2i pos;
        int maxAlt;
        int minAlt;
        sf::Angle heading;
        sf::Angle headingVariant;
        int maxSpeed;
        int minSpeed;
    };

    struct Airport
    {
        std::string name;
        sf::Vector2i pos;
        std::vector<Runway> runways;
    };

    struct Fix
    {
        std::string name;
        sf::Vector2i pos;
    };


public:
    MapInfo(const std::filesystem::path& path);
    void Load(const std::filesystem::path& path);

private:
    Airport airport;
    std::vector<Spawn> spawns;
    std::vector<Airspace> airspaces;
    std::vector<Fix> fixes;
};
