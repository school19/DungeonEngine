//
// Created by Chaz on 7/13/2017.
//

#include "TokenStreamWriter.h"

TokenStreamWriter::TokenStreamWriter(const TokenStream &stream) : mTokenStream(stream){}

TokenStreamWriter::~TokenStreamWriter() {}

void TokenStreamWriter::write()
{
    while(mTokenStream.peek().type() != TokenType::End)
    {
        write(mTokenStream.next());
    }
}