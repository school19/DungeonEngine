//
// Created by Chaz on 9/3/2017.
//

#ifndef DUNGEONENGINE_MAP_H
#define DUNGEONENGINE_MAP_H


#include "Utility.h"
#include "Entity.h"

namespace core{
    class Map {
    public:
        Map() = default;
        virtual ~Map() = default;

    private:
        utility::Size mSize;
    };
}


#endif //DUNGEONENGINE_MAP_H
