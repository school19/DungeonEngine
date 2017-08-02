//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_SERVER_H
#define DUNGEONENGINE_SERVER_H

#include <boost/asio.hpp>
#include <future>
#include "ConnectionManager.h"


class HttpServer {
public:
    HttpServer(boost::asio::io_service& service, unsigned short port);
    ~HttpServer();

private:
    boost::asio::ip::tcp::acceptor mAcceptor;
    boost::asio::signal_set mSignals;
    ConnectionManager mManager;

    boost::asio::ip::tcp::socket mSocket;

    void do_accept();
    void do_signal_await();


};


#endif //DUNGEONENGINE_SERVER_H
