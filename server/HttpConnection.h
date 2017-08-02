//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_HTTPCONNECTION_H
#define DUNGEONENGINE_HTTPCONNECTION_H

#include <boost/asio.hpp>
#include "HttpRequest.h"
#include "HttpResponse.h"
#include "ConnectionManager.h"
#include "RequestHandler.h"
#include "RequestParser.h"

class HttpConnection : public std::enable_shared_from_this<HttpConnection> {
public:
    HttpConnection(boost::asio::ip::tcp::socket&& socket, ConnectionManager& manager, RequestHandler& handler);
    ~HttpConnection();

    void start();
    void stop();

private:
    boost::asio::ip::tcp::socket mSocket;
    std::shared_ptr<HttpRequest> mRequest;
    HttpResponse mResponse;
    RequestParser mParser;

    std::array<char, 8192> mBuffer;


    ConnectionManager& mManager;
    RequestHandler& mHandler;

    void startRead();
};


#endif //DUNGEONENGINE_HTTPCONNECTION_H
