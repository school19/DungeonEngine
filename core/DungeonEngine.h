//
// Created by Chaz on 9/3/2017.
//

#ifndef DUNGEONENGINE_DUNGEONENGINE_H
#define DUNGEONENGINE_DUNGEONENGINE_H

#include "Map.h"
#include "Context.h"

namespace core{
    class DungeonEngine : public Context {
    public:
        DungeonEngine() = default;
        virtual ~DungeonEngine() = default;

        virtual std::shared_ptr<Map> createMap() override;

        const std::vector<std::shared_ptr<Map>> &getMaps() override;

        void removeMap(std::shared_ptr<Map> &ptr) override;

    private:
        std::vector<std::shared_ptr<Map>> mMaps;
    };
}


#endif //DUNGEONENGINE_DUNGEONENGINE_H
