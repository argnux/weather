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
    {"--city", [](WeatherSettings &s, const std::string& arg) { s.city = arg; }},
    {"-c", [](WeatherSettings &s, const std::string& arg) { s.city = arg; }},

    {"--token", [](WeatherSettings &s, const std::string& arg) { s.token = arg; }},
    {"-t", [](WeatherSettings &s, const std::string& arg) { s.token = arg; }},

    {"--address", [](WeatherSettings &s, const std::string& arg) { s.address = arg; }},
    {"-a", [](WeatherSettings &s, const std::string& arg) { s.address = arg; }},

    {"--port", [](WeatherSettings &s, const std::string& arg) { s.port = arg; }},
    {"-p", [](WeatherSettings &s, const std::string& arg) { s.port = arg; }}
};

WeatherSettings parse_settings(int argc, char* argv[])
{
    WeatherSettings settings;

    if (argc == 1) {
        settings.help = true;
    }

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
