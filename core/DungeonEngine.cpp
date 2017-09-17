//
// Created by Chaz on 9/3/2017.
//

#include "DungeonEngine.h"

namespace core {
    std::shared_ptr<Map> DungeonEngine::createMap() {
        return nullptr;
    }

    const std::vector<std::shared_ptr<Map>> &DungeonEngine::getMaps() {
        return mMaps;
    }

    void DungeonEngine::removeMap(std::shared_ptr<Map> &ptr) {

    }
}