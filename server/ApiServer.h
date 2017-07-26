//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_SERVER_H
#define DUNGEONENGINE_SERVER_H

#include <boost/asio.hpp>


class ApiServer {
public:
    ApiServer(boost::asio::io_service& service);
    ~ApiServer();

private:
    boost::asio::ip::tcp::acceptor mAcceptor;

    void start_listening();
};


#endif //DUNGEONENGINE_SERVER_H
