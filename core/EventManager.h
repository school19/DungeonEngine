//
// Created by Chaz on 9/5/2017.
//

#ifndef DUNGEONENGINE_EVENTMANAGER_H
#define DUNGEONENGINE_EVENTMANAGER_H

#include <queue>

#include "Event.h"

namespace core{
    class EventManager {
    public:
        EventManager();
        ~EventManager();



    private:
        std::queue<Event> mQueue;
    };
}


#endif //DUNGEONENGINE_EVENTMANAGER_H
