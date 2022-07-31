#include "network.hpp"
#include <iostream>

namespace NetworkLayer {
    Network::Network(const ContextPtr &context_ptr, IPAddress connectionIP)
        : m_context(context_ptr), m_ip(connectionIP), m_stream(m_context->get_executor())
    {

    }

    bool Network::start()
    {
        tcp::resolver resolver(m_context->get_executor());
        tcp::resolver::results_type results;
        try {
            results = resolver.resolve(m_ip.host, m_ip.port);
        } catch (const boost::wrapexcept<boost::system::system_error> &wrap_er) {
            std::cerr << "ERROR: Incorrect address" << std::endl;
            exit(-2);
        }

        beast::error_code er;
        m_stream.connect(results, er);

        return !er.failed();
    }

    void Network::send(const std::string &city_name, const std::string &token)
    {
        const std::string target = "/data/2.5/weather?q=" + city_name + "&appid=" + token + "&units=metric";
        http::request<http::string_body> request{http::verb::get, target, 10};

        send(request);
    }

    std::string Network::receive()
    {
        auto response = p_receive();

        auto json_result = beast::buffers_to_string(response.body().data());
        
        pt::ptree tree;
        std::istringstream is(json_result);
        pt::read_json(is, tree);

        std::ostringstream os;
        try {
            os << "City: " << tree.get<std::string>("name") << '\n';
            os << "Temperature: " << tree.get<std::string>("main.temp") << "°C" << '\n';
            os << "Wind's speed: " << tree.get<std::string>("wind.speed") << " meter/sec" << '\n';
            os << "Wind's direction: " << tree.get<std::string>("wind.deg") << "°";
        } catch (const boost::wrapexcept<boost::property_tree::ptree_bad_path> &er) {
            std::cerr << "ERROR: Undefined city" << std::endl;
            exit(-4);
        }

        return os.str();
    }

    void Network::send(const http::request<http::string_body> &request)
    {
        try {
            http::write(m_stream, request);
        } catch (const boost::wrapexcept<boost::system::system_error> &er) {
            std::cerr << "ERROR: Incorrect port" << std::endl;
            exit(-3);
        }
    }

    http::response<http::dynamic_body> Network::p_receive()
    {
        beast::flat_buffer buffer;
        http::response<http::dynamic_body> response;

        http::read(m_stream, buffer, response);
        return response;
    }
};
