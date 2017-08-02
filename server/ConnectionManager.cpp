//
// Created by Chaz on 7/29/2017.
//

#include "ConnectionManager.h"

#include "HttpConnection.h"

ConnectionManager::ConnectionManager()
{
}

ConnectionManager::~ConnectionManager()
{
}

void ConnectionManager::start(std::shared_ptr<HttpConnection> c)
{
    mConnections.insert(c);
    c->start();
}

void ConnectionManager::stop(std::shared_ptr<HttpConnection> c)
{
    mConnections.erase(c);
    c->stop();
}

void ConnectionManager::stopAll()
{
    for(auto c : mConnections)
    {
        c->stop();
    }
    mConnections.clear();
}