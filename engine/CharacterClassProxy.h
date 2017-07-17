//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_CHARACTERCLASSPROXY_H
#define DUNGEONENGINE_CHARACTERCLASSPROXY_H

#include <memory>

#include "CharacterClass.h"


class CharacterClassProxy : public CharacterClass{
protected:
    CharacterClassProxy();
public:
    virtual ~CharacterClassProxy();

private:
    std::unique_ptr<CharacterClass> mPtr;
};


#endif //DUNGEONENGINE_CHARACTERCLASSPROXY_H
