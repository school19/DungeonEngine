//
// Created by chaz on 7/25/17.
//

#ifndef DUNGEONENGINE_HTTPHEADER_H
#define DUNGEONENGINE_HTTPHEADER_H

#include <string>

class HttpHeader {
public:
    HttpHeader(std::string name, std::string value);
    ~HttpHeader();

    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getValue() const;
    void setValue(const std::string &value);

private:
    std::string name;
    std::string value;

};


#endif //DUNGEONENGINE_HTTPHEADER_H
