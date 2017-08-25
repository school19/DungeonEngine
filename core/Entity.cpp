//
// Created by Chaz on 8/22/2017.
//

#include "Entity.h"

void Entity::addComponent(std::shared_ptr<EntityComponent> &component) {
    mComponents.push_back(component);
}

void Entity::removeComponent(std::shared_ptr<EntityComponent> &component) {
    auto itr = std::find(mComponents.begin(), mComponents.end(), component);
    if(itr != mComponents.end())
    {
        mComponents.erase(itr);
    }
}