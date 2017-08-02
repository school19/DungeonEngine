//
// Created by Chaz on 7/30/2017.
//

#include <algorithm>
#include <sstream>
#include "HttpRequest.h"

HttpRequest::HttpRequest(HttpMethod method, std::string&& uri, std::pair<int, int>&& version)
: mMethod(method),
  mUri(uri),
  mVersion(version)
{
}

void HttpRequest::addHeader(HttpHeader &header) {
    mHeaders.push_back(header);
}

HttpHeader HttpRequest::getHeaderByName(std::string name) {
    auto itr = std::find_if(mHeaders.begin(), mHeaders.end(), [&name](const HttpHeader& header)
    {
       return name == header.name;
    });

    if(itr == mHeaders.end())
    {
        std::stringstream msg;
        msg <<"Header " << name << " was not found!";
        throw std::runtime_error(msg.str());
    }

    return *itr;
}

void HttpRequest::setData(std::vector<char> data) {
    mData = data;
}

std::vector<char> HttpRequest::getData()
{
    return mData;
}