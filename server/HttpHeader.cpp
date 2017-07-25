//
// Created by chaz on 7/25/17.
//

#include "HttpHeader.h"

const std::string &HttpHeader::getName() const {
    return name;
}

void HttpHeader::setName(const std::string &name) {
    HttpHeader::name = name;
}

const std::string &HttpHeader::getValue() const {
    return value;
}

void HttpHeader::setValue(const std::string &value) {
    HttpHeader::value = value;
}
