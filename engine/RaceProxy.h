//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_RACEPROXY_H
#define DUNGEONENGINE_RACEPROXY_H


#include <memory>
#include "Race.h"

class RaceProxy : Race {
protected:
    RaceProxy();

public:
    ~RaceProxy();

private:
    std::unique_ptr<Race> mPtr;

};


#endif //DUNGEONENGINE_RACEPROXY_H
