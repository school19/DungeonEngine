//
// Created by Chaz on 7/30/2017.
//

#ifndef DUNGEONENGINE_APIREQUESTHANDLER_H
#define DUNGEONENGINE_APIREQUESTHANDLER_H

#include "RequestHandler.h"

class ApiRequestHandler :public RequestHandler{
public:
    void handle(const HttpRequest &request, HttpResponse &response) override;
};


#endif //DUNGEONENGINE_APIREQUESTHANDLER_H
