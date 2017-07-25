//
// Created by chaz on 7/25/17.
//

#include "HttpServer.h"
#include "HttpConnection.h"

using namespace boost::asio;

HttpServer::HttpServer(io_service &service) :mAcceptor(service, ip::tcp::endpoint(ip::tcp::v4(), 80)){
    this->start_listening();
}

HttpServer::~HttpServer(){}

void HttpServer::start_listening()
{
    std::shared_ptr<HttpConnection> connection = std::make_shared<HttpConnection>(mAcceptor.get_io_service());
    mAcceptor.async_accept(connection->getSocket(), [connection]())
}