//
// Created by Chaz on 9/3/2017.
//

#ifndef DUNGEONENGINE_MAP_H
#define DUNGEONENGINE_MAP_H


#include "Entity.h"

namespace core{
    class Map {
    public:
        Map() = default;
        ~Map() = default;

    private:
        std::vector<std::shared_ptr<entity::Entity>> mEntities;
    };
}


#endif //DUNGEONENGINE_MAP_H
