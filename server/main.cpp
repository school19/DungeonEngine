//
// Created by chaz on 7/25/17.
//
#include <boost/asio.hpp>

using boost::asio::io_service;

int main(int argc, const char* argv[])
{
    using namespace boost::asio::ip;
    io_service service;

    tcp::socket socket(service);

    tcp::endpoint endpoint(tcp::v4(), 80);

    socket.bind(endpoint);
}