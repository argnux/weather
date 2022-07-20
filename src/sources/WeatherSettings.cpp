#include <iostream>
#include <functional>
#include <unordered_map>
#include <stdexcept>
#include "WeatherSettings.hpp"

using NoArgHandle = std::function<void(WeatherSettings&)>;
const std::unordered_map<std::string, NoArgHandle> NoArgs {
    {"--help", [](WeatherSettings &s) { s.help = true; }},
    {"-h", [](WeatherSettings &s) { s.help = true; }}
};

using OneArgHandle = std::function<void(WeatherSettings&, const std::string&)>;
const std::unordered_map<std::string, OneArgHandle> OneArgs {

};

WeatherSettings parse_settings(int argc, char* argv[])
{
    WeatherSettings settings;

    // argv[0] is the program name
    for (int i = 1; i < argc; i++) {
        std::string opt = argv[i];

        auto j = NoArgs.find(opt);
        if (j != NoArgs.end()) {
            j->second(settings);
            continue;
        }
        
        auto k = OneArgs.find(opt);
        if (k != OneArgs.end()) {
            ++i;
            if (i < argc) {
                k->second(settings, argv[i]);
            } else {
                throw std::runtime_error {"Missing param after " + opt};
            }
            continue;
        }

        std::cerr << "Unrecognized command-line option: " << opt << std::endl;
    }

    return settings;
}
