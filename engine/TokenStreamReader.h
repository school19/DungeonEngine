//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_TOKENSTREAMREADER_H
#define DUNGEONENGINE_TOKENSTREAMREADER_H


#include "TokenStream.h"

class TokenStreamReader {
protected:
    TokenStreamReader() = default;
public:
    virtual ~TokenStreamReader() = default;

    virtual TokenStream read() = 0;
};


#endif //DUNGEONENGINE_TOKENSTREAMREADER_H
