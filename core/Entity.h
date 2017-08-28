//
// Created by Chaz on 8/22/2017.
//

#ifndef DUNGEONENGINE_ENTITY_H
#define DUNGEONENGINE_ENTITY_H

#include <memory>
#include <vector>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>

#include "EntityComponent.h"
#include "Error.h"


class Entity {
public:
    Entity();
    ~Entity();

    void addComponent(std::shared_ptr<EntityComponent>& component);
    void removeComponent(std::shared_ptr<EntityComponent>& component);

    template <typename Component>
    std::shared_ptr<Component> get()
    {
        const std::type_index index(typeid(Component));
        auto itr = mComponents.find(index);
        if(itr == mComponents.end())
        {
            BOOST_THROW_EXCEPTION(ComponentNotFound() << ComponentName(index.name()));
        }
    }

private:
    std::unordered_map<std::type_index, std::shared_ptr<EntityComponent>> mComponents;
};


#endif //DUNGEONENGINE_ENTITY_H
