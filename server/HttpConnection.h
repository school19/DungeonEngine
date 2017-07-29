//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_HTTPCONNECTION_H
#define DUNGEONENGINE_HTTPCONNECTION_H

#include <boost/asio.hpp>
#include "HttpRequest.h"
#include "HttpResponse.h"

class HttpConnection {
public:
    HttpConnection(boost::asio::io_service& service);
    ~HttpConnection();

    boost::asio::ip::tcp::socket& getSocket();

    std::shared_ptr<HttpRequest> getRequest();

    void writeResponse(const HttpResponse& response);

private:
    boost::asio::ip::tcp::socket mSocket;

    std::shared_ptr<HttpRequest> mRequest;

    void parseRequest();
};


#endif //DUNGEONENGINE_HTTPCONNECTION_H
