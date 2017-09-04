//
// Created by Chaz on 8/22/2017.
//


#include "Entity.h"
#include "Error.h"
namespace core {
    namespace entity {
        Entity::Entity() {}

        Entity::~Entity() {}

        void Entity::addComponent(std::shared_ptr<EntityComponent> &component) {
            const std::type_index info(typeid(*component));
            auto itr = mComponents.find(std::type_index(info));
            if (itr != mComponents.end()) {
                BOOST_THROW_EXCEPTION(DuplicateComponent() << ComponentType(info));
            }
            mComponents.insert({info, component});
        }

        void Entity::removeComponent(std::shared_ptr<EntityComponent> &component) {
            const std::type_index info(typeid(*component));
            auto itr = mComponents.find(std::type_index(typeid(*component)));
            if (itr == mComponents.end()) {
                BOOST_THROW_EXCEPTION(ComponentNotFound() << ComponentType(info));
            }
            mComponents.erase(itr);
        }
    }
}