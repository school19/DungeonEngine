//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_SERVER_H
#define DUNGEONENGINE_SERVER_H

#include <boost/asio.hpp>
#include <future>
#include "Router.h"


class ApiServer {
public:
    ApiServer(boost::asio::io_service& service, unsigned short port, std::unique_ptr<Router>& router);
    ~ApiServer();

private:
    boost::asio::ip::tcp::acceptor mAcceptor;
    std::vector<std::future<void>> mFutures;

    void start_listening();
    void cleanup(int timeout);

    std::unique_ptr<Router> mRouter;

    std::mutex mFutureCollectionMutex;
};


#endif //DUNGEONENGINE_SERVER_H
