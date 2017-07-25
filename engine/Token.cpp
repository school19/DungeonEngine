//
// Created by Chaz on 7/13/2017.
//

#include "Token.h"

Token::Token(TokenType type, std::string value) : mType(type), mValue(value)
{
}

Token::~Token(){}

TokenType Token::type()
{
    return mType;
}

std::string Token::value()
{
    return mValue;
}

