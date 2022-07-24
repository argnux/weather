#include "client.hpp"

namespace ClientLayer {
    Client::Client(const NetworkLayer::ContextPtr &context_ptr, NetworkLayer::IPAddress connectionIP)
        : m_connection(std::make_shared<NetworkLayer::Network>(context_ptr, connectionIP))
    {

    }

    void Client::process()
    {
        m_connection->start();
        m_connection->send(m_city, m_token);

        const std::string result = m_connection->receive();
        std::cout << result << std::endl;
    }

    void Client::setCity(const std::string &city_name)
    {
        m_city = city_name;
    }

    void Client::setToken(const std::string &token)
    {
        m_token = token;
    }
};
