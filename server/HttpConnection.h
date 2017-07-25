//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_HTTPCONNECTION_H
#define DUNGEONENGINE_HTTPCONNECTION_H

#include <boost/asio.hpp>

class HttpConnection {
public:
    HttpConnection(boost::asio::io_service& service);
    ~HttpConnection();

    boost::asio::ip::tcp::socket& getSocket();

private:
    boost::asio::ip::tcp::socket mSocket;
};


#endif //DUNGEONENGINE_HTTPCONNECTION_H
