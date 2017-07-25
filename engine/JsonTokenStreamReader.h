//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_JSONTOKENSTREAMREADER_H
#define DUNGEONENGINE_JSONTOKENSTREAMREADER_H


#include "TokenStreamReader.h"
#include <rapidjson/istreamwrapper.h>

class JsonTokenStreamReader : public TokenStreamReader{
public:
    JsonTokenStreamReader(std::istream& stream);
    ~JsonTokenStreamReader();

    virtual TokenStream read() override;

private:
    IStreamWrapper mStream;
};


#endif //DUNGEONENGINE_JSONTOKENSTREAMREADER_H
