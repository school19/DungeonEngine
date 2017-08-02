//
// Created by Chaz on 7/29/2017.
//

#include "RequestParser.h"

RequestParser::RequestParser() {
    mState = MethodStart;
}

RequestParser::ResultType RequestParser::consume(char input)
{
    switch(mState)
    {
        case MethodStart:
            if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return Bad;
            }
            else
            {
                mState = Method;
                mTmpMethod.push_back(input);
                return Indeterminate;
            }
        case Method:
            if(input == ' ')
            {
                mState = Uri;

                return Indeterminate;
            }
            else if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return Bad;
            }
            else
            {
                mTmpMethod.push_back(input);
                return Indeterminate;
            }
        case Uri:
            if(input == ' ')
            {
                mState = HttpVersionH;
                return Indeterminate;
            }
            else if (is_ctl(input))
            {
                return Bad;
            }
            else
            {
                mUri.push_back(input);
                return Indeterminate;
            }
        case HttpVersionH:
            if(input == 'H')
            {
                mState = HttpVersionT1;
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case HttpVersionT1:
            if(input == 'T')
            {
                mState = HttpVersionT2;
                return Indeterminate;
            }
            else{
                return Bad;
            }

        case HttpVersionT2:
            if(input == 'T')
            {
                mState = HttpVersionP;
                return Indeterminate;
            }
            else{
                return Bad;
            }
        case HttpVersionP:
            if(input == 'P')
            {
                mState = HttpVersionSlash;
                return Indeterminate;
            }
            else{
                return Bad;
            }
        case HttpVersionSlash:
            if(input == '/')
            {
                mMajorVersion = 0;
                mMinorVersion = 0;
                mState = HttpVersionMajorStart;
                return Indeterminate;
            }
            else{
                return Bad;
            }
        case HttpVersionMajorStart:
            if(is_digit(input))
            {
                mMajorVersion = mMajorVersion * 10 + input - '0';
                mState = HttpVersionMajor;
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case HttpVersionMajor:
            if(input == '.')
            {
                mState = HttpVersionMinorStart;
                return Indeterminate;
            }
            else if(is_digit(input))
            {
                mMajorVersion = mMajorVersion *10 + input - '0';
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case HttpVersionMinorStart:
            if(is_digit(input))
            {
                mMinorVersion = mMinorVersion * 10 + input - '0';
                mState = HttpVersionMinor;
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case HttpVersionMinor:
            if(input == '\r')
            {
                mState = Newline1;
                return Indeterminate;
            }
            else if(is_digit(input))
            {
                mMinorVersion = mMinorVersion * 10 + input - '0';
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case Newline1:
            if(input == '\n')
            {
                mState = HeaderLineStart;
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case HeaderLineStart:
            if(input == '\r')
            {
                mState = Newline3;
                return Indeterminate;
            }
            else if(!mHeaders.empty() && (input == ' ' || input == '\t'))
            {
                mState = HeaderLws;
                return Indeterminate;
            }
            else if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return Bad;
            }
            else
            {
                mHeaders.push_back(HttpHeader());
                mHeaders.back().name.push_back(input);
                mState = HeaderName;
                return Indeterminate;
            }
        case HeaderLws:
            if(input == '\r')
            {
                mState = Newline2;
                return Indeterminate;
            }
            else if (input == ' ' || input == '\t')
            {
                return Indeterminate;
            }
            else if (is_ctl(input))
            {
                return Bad;
            }
            else
            {
                mState = HeaderValue;
                mHeaders.back().value.push_back(input);
                return Indeterminate;
            }
        case HeaderName:
            if(input == ':')
            {
                mState = SpaceBeforeHeaderValue;
                return Indeterminate;
            }
            else if(!is_char(input) || is_ctl(input) || is_tspecial(input))
            {
                return Bad;
            }
            else
            {
                mHeaders.back().name.push_back(input);
                return Indeterminate;
            }
        case SpaceBeforeHeaderValue:
            if(input == ' ')
            {
                mState =HeaderValue;
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case HeaderValue:
            if(input == '\r')
            {
                mState = Newline2;
                return Indeterminate;
            }
            else if(is_ctl(input))
            {
                return Bad;
            }
            else
            {
                mHeaders.back().value.push_back(input);
            }
        case Newline2:
            if(input == '\n')
            {
                mState = HeaderLineStart;
                return Indeterminate;
            }
            else
            {
                return Bad;
            }
        case Newline3:
            return (input == '\n')?Good:Bad;
        default:
            return Bad;
    }
}

std::shared_ptr<HttpRequest> RequestParser::getRequest() {
    std::shared_ptr<HttpRequest> request = std::make_shared<HttpRequest>(method_from_string(mTmpMethod), mUri, std::make_pair(mMajorVersion, mMinorVersion));
    for(auto& header : mHeaders)
    {
        request->addHeader(header);
    }
    return request;
}

bool RequestParser::is_char(int c)
{
    return c >= 0 && c <= 127;
}

bool RequestParser::is_ctl(int c)
{
    return (c >= 0 && c <= 31) || (c == 127);
}

bool RequestParser::is_tspecial(int c)
{
    switch (c)
    {
        case '(': case ')': case '<': case '>': case '@':
        case ',': case ';': case ':': case '\\': case '"':
        case '/': case '[': case ']': case '?': case '=':
        case '{': case '}': case ' ': case '\t':
            return true;
        default:
            return false;
    }
}

bool RequestParser::is_digit(int c)
{
    return c >= '0' && c <= '9';
}

HttpMethod RequestParser::method_from_string(const std::string & val) {
    if(val == "GET")
    {
        return Get;
    }
    if(val == "POST")
    {
        return Post;
    }
    if(val == "PUT")
    {
        return Put;
    }
    if(val == "DELETE")
    {
        return Delete;
    }
    if(val == "OPTIONS")
    {
        return Options;
    }
    if(val == "TRACE")
    {
        return Trace;
    }
    if(val == "HEAD")
    {
        return Head;
    }
    if(val == "CONNECT")
    {
        return Connect;
    }
    if(val == "PATCH")
    {
        return Patch;
    }
}

void RequestParser::reset()
{
    mUri.clear();
    mHeaders.clear();
    mMajorVersion = 0;
    mMinorVersion = 0;
    mTmpMethod.clear();
    mState = MethodStart;
}