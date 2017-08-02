//
// Created by Chaz on 7/29/2017.
//

#ifndef DUNGEONENGINE_REQUESTHANDLER_H
#define DUNGEONENGINE_REQUESTHANDLER_H


#include "HttpRequest.h"
#include "HttpResponse.h"

class RequestHandler {
public:
    virtual void handle(const HttpRequest& request, HttpResponse& response) = 0;
};


#endif //DUNGEONENGINE_REQUESTHANDLER_H
