#include "application.hpp"

#include <iostream>

Application::Application(int argc, char* argv[]) : mSettings{parse_settings(argc, argv)}
{

}

void Application::help_output()
{
    std::cout << "Options:\n"
      << "  -h [ --help ]         Show help\n"
      << "  -c [ --city ] arg     Enter city (If the city name is divided into several \n"
      << "                        words - use _ instead of space)\n"
      << "  -t [ --token ] arg    Enter token\n"
      << "  -a [ --address ] arg  Enter host address\n"
      << "  -p [ --port ] arg     Enter port" << std::endl;
}

int Application::exec()
{
    if (mSettings.help) {
        help_output();
        return 0;
    }
}
