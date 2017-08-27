//
// Created by Chaz on 8/22/2017.
//


#include "Entity.h"

Entity::Entity()
{}

Entity::~Entity()
{}

void Entity::addComponent(std::shared_ptr<EntityComponent> &component) {
    auto itr = mComponents.find(std::type_index(typeid(*component)));
    if(itr != mComponents.end())
    {
        //There's already a component of this type.
        //TODO: Decide if this is an error or not.
    }
    mComponents.insert({std::type_index(typeid(*component)), component});
}

void Entity::removeComponent(std::shared_ptr<EntityComponent> &component) {
    auto itr = mComponents.find(std::type_index(typeid(*component)));
    if(itr != mComponents.end())
    {
        mComponents.erase(itr);
    }
}