//
// Created by chaz on 7/25/17.
//
#include <boost/asio.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include "ApiServer.h"

using boost::asio::io_service;

void parse_program_args(int argc, const char* argv[], boost::program_options::variables_map& storage)
{
    using namespace boost::program_options;
    options_description description;
    description.add_options()
            .("port,p", value<unsigned short>()->default_value(80), "Port the server will listen on");

    store(parse_command_line(argc, argv, description), storage);
    storage.notify();
}

int main(int argc, const char* argv[])
{
    using namespace boost::asio::ip;
    using namespace boost::program_options;

    variables_map arguments;

    io_service service;

    ApiServer server(service, arguments["port"].as<unsigned short>());

    try{
        service.run();
    }
    catch(std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    return 0;
}