//
// Created by Chaz on 9/6/2017.
//

#ifndef DUNGEONENGINE_CONTEXT_H
#define DUNGEONENGINE_CONTEXT_H

#include <memory>
#include "EventManager.h"
#include "Map.h"

namespace core {
    class Context {
    protected:
        Context() = default;
    public:
        virtual ~Context() = default;

        virtual std::shared_ptr<Map> createMap() = 0;
        virtual const std::vector<std::shared_ptr<Map>>& getMaps() = 0;
        virtual void removeMap(std::shared_ptr<Map>&) = 0;
    };

}


#endif //DUNGEONENGINE_CONTEXT_H
