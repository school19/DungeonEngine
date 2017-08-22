//
// Created by chaz on 8/5/17.
//

#include "server.h"

namespace core {
    server::server(boost::asio::io_service &service, unsigned short port, int threads) : service(service),
                                                                                         socket(service),
                                                                                         acceptor(service),
                                                                                         signal_set(service) {
        signal_set.add(SIGINT);
        signal_set.add(SIGTERM);

        async_await();

        acceptor.bind({boost::asio::ip::tcp::v4(), port});
        acceptor.open(boost::asio::ip::tcp::v4());
        do_accept();

        this->threads.reserve(threads);
        this->threads.emplace_back([this]() {
            this->service.run();
        });
    }

    server::~server() {

    }

    void server::run() {
        service.run();
    }

    void server::do_accept() {
        acceptor.async_accept(socket, [this](const boost::system::error_code &ec) {
            //move the socket over to a connection handler to be defined later
            do_accept();
        });
    }

    void server::async_await() {
        signal_set.async_wait(
                [this](const boost::system::error_code &ec, int /*signo*/) {

                });
    }
}