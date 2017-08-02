//
// Created by chaz on 7/25/17.
//

#include "HttpConnection.h"

HttpConnection::HttpConnection(boost::asio::ip::tcp::socket&& socket, ConnectionManager& manager, RequestHandler& handler) : mSocket(std::move(socket)), mManager(manager), mHandler(handler)
{}

HttpConnection::~HttpConnection() {
    mSocket.shutdown(mSocket.shutdown_both);
    mSocket.close();
}

void HttpConnection::start()
{
    mParser.reset();
    startRead();
}

void HttpConnection::stop()
{
    mSocket.close();
}

void HttpConnection::startRead()
{
    auto self(shared_from_this());
    mSocket.async_read_some(boost::asio::buffer(mBuffer),
    [this, self](boost::system::error_code ec, std::size_t bytes_transferred)
    {
        if(!ec)
        {
            RequestParser::ResultType result;
            auto result_itr = mBuffer.begin();
            auto end = mBuffer.begin();
            std::advance(end, bytes_transferred);
            std::tie(result, result_itr) = mParser.parse(mBuffer.begin(), end);
        }
    });
}