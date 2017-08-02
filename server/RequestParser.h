//
// Created by Chaz on 7/29/2017.
//

#ifndef DUNGEONENGINE_REQUESTPARSER_H
#define DUNGEONENGINE_REQUESTPARSER_H

#include <tuple>
#include <memory>
#include "HttpRequest.h"

class RequestParser {
public:
    RequestParser();

    void reset();

    enum ResultType {Good, Bad, Indeterminate};

    template <typename InputIterator>
    std::tuple<ResultType, InputIterator> parse( InputIterator begin, InputIterator end)
    {
        while(begin != end)
        {
            ResultType  result = consume(*begin++);
            if(result == Good || result == Bad)
            {
                return std::make_tuple(result, begin);
            }
            return std::make_tuple(Indeterminate, begin);
        }
    };

    std::shared_ptr<HttpRequest> getRequest();
private:
    ResultType consume(char input);

    static bool is_char(int c);
    static bool is_ctl(int c);
    static bool is_tspecial(int c);
    static bool is_digit(int c);
    static HttpMethod method_from_string(const std::string&);

    enum State{
        MethodStart,
        Method,
        Uri,
        HttpVersionH,
        HttpVersionT1,
        HttpVersionT2,
        HttpVersionP,
        HttpVersionSlash,
        HttpVersionMajorStart,
        HttpVersionMajor,
        HttpVersionMinorStart,
        HttpVersionMinor,
        Newline1,
        HeaderLineStart,
        HeaderLws,
        HeaderName,
        SpaceBeforeHeaderValue,
        HeaderValue,
        Newline2,
        Newline3
    };

    State mState;

    std::string mTmpMethod;
    std::string mUri;
    std::vector<HttpHeader> mHeaders;
    int mMajorVersion;
    int mMinorVersion;
};


#endif //DUNGEONENGINE_REQUESTPARSER_H
