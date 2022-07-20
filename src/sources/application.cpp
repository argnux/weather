#include "application.hpp"

#include <iostream>
#include <fstream>

Application::Application(int argc, char* argv[]) : mSettings{parse_settings(argc, argv)}
{
	if (mSettings.help) {
		return;
	}

	if (!mSettings.token.has_value()) {
		std::ifstream token_data;
		token_data.open("token.txt");
		if (!token_data) {
			std::cerr << "No file!" << std::endl;
			return;
		}

		std::string token;
		token_data >> token;
		mSettings.token = token;
	}
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
