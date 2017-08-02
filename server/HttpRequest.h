//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_HTTPREQUEST_H
#define DUNGEONENGINE_HTTPREQUEST_H

#include <vector>
#include <unordered_map>
#include "HttpHeader.h"

enum HttpMethod
{
    Get,
    Post,
    Put,
    Delete,
    Options,
    Trace,
    Head,
    Connect,
    Patch
};

class HttpRequest {
public:
    HttpRequest(HttpMethod method, std::string&& uri, std::pair<int,int>&& version);
    HttpRequest(const HttpRequest&) = default;
    HttpRequest(HttpRequest&&) = default;
    ~HttpRequest() = default;

    void addHeader(HttpHeader& header);
    HttpHeader getHeaderByName(std::string name);

    void setData(std::vector<char> data);
    std::vector<char> getData();

private:
    HttpMethod mMethod;
    std::pair<int,int> mVersion;
    std::string mUri;
    std::vector<HttpHeader> mHeaders;
    std::vector<char> mData;
};


#endif //DUNGEONENGINE_HTTPREQUEST_H
