//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_CHARACTERCLASSINSTANCE_H
#define DUNGEONENGINE_CHARACTERCLASSINSTANCE_H

#include <memory>

#include "CharacterClass.h"

class CharacterClassInstance {
public:
    CharacterClassInstance();
    ~CharacterClassInstance();

private:
    bool mPrimaryClass;
    std::unique_ptr<CharacterClass> mPtr;
};


#endif //DUNGEONENGINE_CHARACTERCLASSINSTANCE_H
