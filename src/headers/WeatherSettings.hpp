#pragma once

#include <optional>
#include <string>

struct WeatherSettings {
    bool help {false};
};

WeatherSettings parse_settings(int argc, char* argv[]);
