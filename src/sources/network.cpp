#include "network.hpp"

#include <iostream> // FIXME temporarily, only to log

namespace NetworkLayer {
    Network::Network(const ContextPtr &context_ptr, IPAddress connectionIP)
        : m_context(context_ptr), m_ip(connectionIP)
    {

    }

    bool Network::start()
    {
        // FIXME write start() function
        std::cout << "Network::start()" << std::endl;
        return false;
    }

    void Network::send(const std::string &city_name, const std::string &token)
    {
        // FIXME write send(const std::string &, const std::string &) function
        std::cout << "Network::send(" << city_name << ", " << token << ")" << std::endl;
    }

    std::string Network::receive()
    {
        // FIXME write receive() function
        std::cout << "Network::receive()" << std::endl;
        return {};
    }

    void Network::send(const http::request<http::string_body> &request)
    {
        // FIXME write send(const http::request<http::string_body> &) function
        std::cout << "Network::send()" << std::endl;
    }

    http::response<http::dynamic_body> Network::p_receive()
    {
        // FIXME write p_receive() function
        std::cout << "Network::p_receive()" << std::endl;
        return {};
    }
};
