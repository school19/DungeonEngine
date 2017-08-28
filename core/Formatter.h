//
// Created by Chaz on 8/27/2017.
//

#ifndef DUNGEONENGINE_FORMATTER_H
#define DUNGEONENGINE_FORMATTER_H


#include <string>
#include <sstream>

class Formatter {
public:
    Formatter(){}
    ~Formatter(){}

    void clear(){
        using namespace std::string_literals;
        mStream.str(""s);
    }
    const std::string& str(){
        return mStream.str();
    }

    template <typename Arg>
    Formatter& operator <<(Arg& a)
    {
        mStream << a;
        return *this;
    }

private:
    std::stringstream mStream;
};


#endif //DUNGEONENGINE_FORMATTER_H
