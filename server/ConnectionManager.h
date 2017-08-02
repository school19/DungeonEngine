//
// Created by Chaz on 7/29/2017.
//

#ifndef DUNGEONENGINE_CONNECTIONMANAGER_H
#define DUNGEONENGINE_CONNECTIONMANAGER_H

#include <unordered_set>
#include <memory>

class HttpConnection;

class ConnectionManager {
public:
    ConnectionManager();
    ~ConnectionManager();

    void start(std::shared_ptr<HttpConnection> c);
    void stop(std::shared_ptr<HttpConnection> c);

    void stopAll();

private:
    std::unordered_set<std::shared_ptr<HttpConnection>> mConnections;
};


#endif //DUNGEONENGINE_CONNECTIONMANAGER_H
