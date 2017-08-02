//
// Created by chaz on 7/25/17.
//

#include <iostream>
#include "HttpServer.h"
#include "HttpConnection.h"

using namespace boost::asio;

HttpServer::HttpServer(io_service &service, unsigned short port, std::shared_ptr<Router> router) :mAcceptor(service, ip::tcp::endpoint(ip::tcp::v4(), port)), mSignals(service), mSocket(service), mRouter(router){
    mSignals.add(SIGINT);
    mSignals.add(SIGTERM);
#ifdef SIGQUIT
    mSignals.add(SIGQUIT);
#endif

    do_signal_await();

    mAcceptor.listen(20);
    this->do_accept();
}

HttpServer::~HttpServer(){
}

void HttpServer::do_accept()
{
    mAcceptor.async_accept(mSocket, [this](const boost::system::error_code& ec){
        if(!mAcceptor.is_open())
        {
            return;
        }

        if(!ec) {
            mManager.start(std::make_shared<HttpConnection>(std::move(mSocket), mManager, ));
        }
        this->do_accept();
    });
}

void HttpServer::do_signal_await() {
    mSignals.async_wait(
            [this](boost::system::error_code ec, int signo)
                        {
                            mAcceptor.close();
                            mManager.stopAll();
                        });
}