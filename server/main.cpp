//
// Created by chaz on 7/25/17.
//
#include <boost/asio.hpp>
#include <boost/program_options.hpp>
#include "server.h"
#include "utility.h"

using namespace boost::asio;
using namespace boost::asio::ip;
using namespace boost::program_options;

void parse_program_args(int argc, const char* argv[], variables_map& storage)
{
    using namespace boost::program_options;
    options_description description;
    description.add_options()
            ("port,p", value<unsigned short>()->default_value(80), "Port the server will listen on")
            ("threads,t", value<unsigned int>()->default_value(std::thread::hardware_concurrency()), "Number of threads to run for the server");

    store(parse_command_line(argc, argv, description), storage);
    storage.notify();
}


int main(int argc, const char* argv[])
{

    variables_map args;
    parse_program_args(argc, argv, args);

    io_service service;

    api::server s(service, args["port"].as<unsigned short>(), args["threads"].as<unsigned int>());
    s.run();

    return 0;
}