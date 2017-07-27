//
// Created by chaz on 7/26/17.
//

#ifndef DUNGEONENGINE_CONTROLLER_H
#define DUNGEONENGINE_CONTROLLER_H


#include "HttpConnection.h"

class Controller {
public:
    Controller();
    ~Controller();

    virtual void handle(std::shared_ptr<HttpConnection> connection) = 0;
};


#endif //DUNGEONENGINE_CONTROLLER_H
