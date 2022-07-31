#include "application.hpp"

#include <iostream>
#include <fstream>
#include <boost/dll.hpp>

Application::Application(int argc, char* argv[]) : m_desc("Options"), m_context(std::make_shared<boost::asio::io_context>())
{
	m_desc.add_options()
		("help,h", "Show help")
		("city,c", po::value<std::string>(), "Enter city (If the city name is divided into several words - use _ instead of space)")
		("token,t", po::value<std::string>(), "Enter token")
		("address,a", po::value<std::string>(), "Enter host address")
		("port,p", po::value<std::string>(), "Enter port")
	;
	po::parsed_options parsed = po::command_line_parser(argc, argv).options(m_desc).allow_unregistered().run();
	po::store(parsed, m_variables_map);
	po::notify(m_variables_map);
}

int Application::exec()
{
	if (m_variables_map.count("help") || m_variables_map.size() == 0) {
		std::cout << m_desc << std::endl;
		return 0;
	}

	std::string token, city, host, port;

	if (!m_variables_map.count("token")) {
		std::ifstream token_data;
		token_data.open(boost::dll::program_location().parent_path().string() + "/token.txt");
		if (!token_data) {
			std::cerr << "There is no token!" << std::endl;
			return -1;
		}
		token_data >> token;
	} else {
		token = m_variables_map["token"].as<std::string>();
	}

	if (!m_variables_map.count("city")) {
		std::cerr << "There is no city!" << std::endl;
		return -1;
	}
	city = m_variables_map["city"].as<std::string>();

	host = m_variables_map.count("address") ? m_variables_map["address"].as<std::string>() : "api.openweathermap.org";
	port = m_variables_map.count("port") ? m_variables_map["port"].as<std::string>() : "80";
	
	ClientLayer::Client client(m_context, {host, port});
	client.setCity(city);
	client.setToken(token);
	client.process();

	return 0;
}
