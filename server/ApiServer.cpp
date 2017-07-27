//
// Created by chaz on 7/25/17.
//

#include <iostream>
#include "ApiServer.h"
#include "HttpConnection.h"

using namespace boost::asio;

ApiServer::ApiServer(io_service &service, unsigned short port, std::unique_ptr<Router>& router) :mAcceptor(service, ip::tcp::endpoint(ip::tcp::v4(), port)){
    mRouter = std::move(router);
    this->start_listening();
}

ApiServer::~ApiServer(){
    cleanup(1);
}

void ApiServer::start_listening()
{
    std::shared_ptr<HttpConnection> connection = std::make_shared<HttpConnection>(mAcceptor.get_io_service());
    mAcceptor.async_accept(connection->getSocket(), [this, &connection](const boost::system::error_code& code){
        std::lock_guard guard(mFutureCollectionMutex);
        mFutures.push_back(std::async(std::launch::async, [&mRouter, &connection](){
            mRouter->route(connection);
        }));
        this->start_listening();
    });

    //passing 0 to cleanup just clears all of the finished threads
    cleanup(0);
}

void ApiServer::cleanup(int timeout)
{
    std::lock_guard guard(mFutureCollectionMutex);
    auto itr = std::remove_if(mFutures.begin(), mFutures.end(), [](std::future<void>& future)
    {
        try {
            auto result = future.wait_for(std::chrono::seconds(timeout));
            if(result == std::future_status::ready)
            {
                future.get();
                return true;
            }

            return false;
        }
        catch(std::exception& exception)
        {
            std::cerr << exception.what() << "\n";
        }
        return true;
    });

    mFutures.erase(itr, mFutures.end());
}