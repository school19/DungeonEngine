//
// Created by chaz on 7/26/17.
//

#include "Router.h"

Router::Router(){}

Router::~Router(){}

void Router::addRoute(std::string base, ControllerFactoryMethod method) {
    mRoutes.insert(std::make_pair(base, method));
}

void Router::route(std::shared_ptr<HttpConnection> connection) {

}