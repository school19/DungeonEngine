//
// Created by Chaz on 9/3/2017.
//

#ifndef DUNGEONENGINE_DUNGEONENGINE_H
#define DUNGEONENGINE_DUNGEONENGINE_H

#include "Map.h"

namespace core{
    class DungeonEngine {
    public:
        DungeonEngine() = default;
        ~DungeonEngine() = default;

    private:
        std::vector<std::unique_ptr<Map>> mMaps;
        int mActiveMapIndex;
    };
}


#endif //DUNGEONENGINE_DUNGEONENGINE_H
