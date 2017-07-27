//
// Created by chaz on 7/26/17.
//

#ifndef DUNGEONENGINE_ROUTER_H
#define DUNGEONENGINE_ROUTER_H


#include <unordered_map>
#include "Controller.h"

typedef std::shared_ptr<Controller>(*ControllerFactoryMethod)();

class Router {
public:
    Router();
    ~Router();

    void addRoute(std::string base, ControllerFactoryMethod method);
    void route(std::shared_ptr<HttpConnection> connection);

private:
    std::unordered_map<std::string, ControllerFactoryMethod> mRoutes;

};


#endif //DUNGEONENGINE_ROUTER_H
