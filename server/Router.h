//
// Created by chaz on 8/1/17.
//

#ifndef DUNGEONENGINE_ROUTER_H
#define DUNGEONENGINE_ROUTER_H


#include <memory>
#include "HttpRequest.h"
#include "Route.h"
#include "HttpResponse.h"

typedef void(*RequestHandler)(std::shared_ptr<HttpRequest> request, std::shared_ptr<HttpResponse> response);

class Router {

    Route get(std::string uri, RequestHandler handler);
    Route post(std::string uri, RequestHandler handler);
    Route put(std::string uri, RequestHandler handler);
    Route patch(std::string uri, RequestHandler handler);

};


#endif //DUNGEONENGINE_ROUTER_H
