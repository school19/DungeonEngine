//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_TOKENSTREAMWRITER_H
#define DUNGEONENGINE_TOKENSTREAMWRITER_H


#include "TokenStream.h"

class TokenStreamWriter {
protected:
    TokenStreamWriter(const TokenStream& stream);

public:
    ~TokenStreamWriter() = default;

    virtual void write(Token t) = 0;

    virtual void write();

private:
    TokenStream mTokenStream;
};


#endif //DUNGEONENGINE_TOKENSTREAMWRITER_H
