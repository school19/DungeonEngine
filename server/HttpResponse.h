//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_HTTPRESPONSE_H
#define DUNGEONENGINE_HTTPRESPONSE_H


#include <vector>
#include "HttpHeader.h"

struct HttpResponse {
    enum StatusCode{
        Ok = 200,
        Created = 201,
        Accepted = 202,
        NoContent = 204,
        BadRequest = 400,
        Unauthorized = 401,
        Forbidden = 403,
        NotFound = 404,
        InternalServerError = 500,
        NotImplemented = 501,
        BadGateway = 502,
        ServiceUnavailable = 503
    };

    StatusCode  status;
    std::vector<HttpHeader> headers;
    std::string content;
};


#endif //DUNGEONENGINE_HTTPRESPONSE_H
