#pragma once

#include <optional>
#include <string>

struct WeatherSettings {
    bool help {false};
    std::optional<std::string> city;
    std::optional<std::string> token;
    std::optional<std::string> address;
    std::optional<std::string> port;
};

WeatherSettings parse_settings(int argc, char* argv[]);
