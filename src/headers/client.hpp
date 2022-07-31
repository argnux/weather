#pragma once

#include <memory>
#include <iostream>
#include "network.hpp"

namespace ClientLayer
{
    using tcp = NetworkLayer::tcp;

    class Client
    {
    public:
        /**
         * @brief Ctor
         * @param context_ptr - smart pointer to io_context
         * @param connectionIP - structure that contains host and port for connection
         * */
        Client(const NetworkLayer::ContextPtr &context_ptr, NetworkLayer::IPAddress connectionIP);

        /**
         * @brief Main function that connections to server, sends request and shows result
         * */
        void process();

        void setCity(const std::string &city_name);
        void setToken(const std::string &token);

    private:
        std::shared_ptr<NetworkLayer::Network> m_connection;

        std::string m_city;
        std::string m_token;
    };
}
