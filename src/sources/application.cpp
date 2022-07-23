#include "application.hpp"

#include <iostream>
#include <fstream>
#include <boost/dll.hpp>

Application::Application(int argc, char* argv[]) : mDesc("Options")
{
	mDesc.add_options()
		("help,h", "Show help")
		("city,c", po::value<std::string>(), "Enter city (If the city name is divided into several words - use _ instead of space)")
		("token,t", po::value<std::string>(), "Enter token")
		("address,a", po::value<std::string>(), "Enter host address")
		("port,p", po::value<std::string>(), "Enter port")
	;
	po::parsed_options parsed = po::command_line_parser(argc, argv).options(mDesc).allow_unregistered().run();
	po::store(parsed, mVariablesMap);
	po::notify(mVariablesMap);
}

int Application::exec()
{
	if (mVariablesMap.count("help") || mVariablesMap.size() == 0) {
		std::cout << mDesc << std::endl;
		return 0;
	}

	std::string token;
	if (!mVariablesMap.count("token")) {
		std::ifstream token_data;
		token_data.open(boost::dll::program_location().parent_path().string() + "/token.txt");
		if (!token_data) {
			std::cerr << "There is no token!" << std::endl;
			return -1;
		}
		token_data >> token;
	} else {
		token = mVariablesMap["token"].as<std::string>();
	}
}
