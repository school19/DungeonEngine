//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_TOKENSTREAM_H
#define DUNGEONENGINE_TOKENSTREAM_H

#include "Token.h"

#include <deque>

class TokenStream {
public:
    TokenStream();
    ~TokenStream() = default;

    Token next();
    Token peek();

    void append(Token t);
    void prepend(Token t);

    void reset();

private:
    std::deque<Token> mTokens;
    int mIndex;
};


#endif //DUNGEONENGINE_TOKENSTREAM_H
