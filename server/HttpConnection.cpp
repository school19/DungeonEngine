//
// Created by chaz on 7/25/17.
//

#include "HttpConnection.h"

HttpConnection::HttpConnection(boost::asio::io_service &service) : mSocket(service)
{}

HttpConnection::~HttpConnection() {
    mSocket.shutdown(mSocket.shutdown_both);
    mSocket.close();
}

boost::asio::ip::tcp::socket& HttpConnection::getSocket() {
    return mSocket;
}