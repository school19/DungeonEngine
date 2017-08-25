//
// Created by Chaz on 8/22/2017.
//

#ifndef DUNGEONENGINE_ENTITY_H
#define DUNGEONENGINE_ENTITY_H

#include <memory>
#include <vector>

#include "EntityComponent.h"

class Entity {
public:
    Entity();
    ~Entity();

    void addComponent(std::shared_ptr<EntityComponent>& component);
    void removeComponent(std::shared_ptr<EntityComponent>& component);

private:
    std::vector<std::shared_ptr<EntityComponent>> mComponents;
};


#endif //DUNGEONENGINE_ENTITY_H
