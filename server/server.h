//
// Created by chaz on 8/5/17.
//

#ifndef DUNGEONENGINE_SERVER_H
#define DUNGEONENGINE_SERVER_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <thread>

namespace core {
    class server {
    public:
        server(boost::asio::io_service &service, unsigned short port, int threads);

        ~server();

        void run();

    private:
        void do_accept();

        void async_await();

        boost::asio::io_service &service;

        boost::asio::signal_set signal_set;

        boost::asio::ip::tcp::acceptor acceptor;

        boost::asio::ip::tcp::socket socket;

        std::vector<std::thread> threads;
    };
}

#endif //DUNGEONENGINE_SERVER_H
