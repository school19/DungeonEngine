//
// Created by Chaz on 8/25/2017.
//

#ifndef DUNGEONENGINE_ENTITYOPERATION_H
#define DUNGEONENGINE_ENTITYOPERATION_H


#include "Entity.h"


namespace core{
    namespace entity{
        class EntityOperation {
        public:
            EntityOperation();
            virtual ~EntityOperation();

            virtual void apply(std::shared_ptr<Entity> & entity) = 0;
        };
    }
}


#endif //DUNGEONENGINE_ENTITYOPERATION_H
