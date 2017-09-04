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

#include <iostream>

namespace core{
    namespace entity{
        class Entity {
        public:
            Entity();
            ~Entity();

            /** @brief adds a component to the entity
             *
             * @param component the component to add to the entity
             *
             * @throws DuplicateComponent when a component of the same type is attempted to be added
             */
            void addComponent(std::shared_ptr<EntityComponent>& component);

            /** @brief removes a component from the entity
             *
             * @param component the component to remove
             *
             * @throws ComponentNotFound if the component does not belong to the entity
             */
            void removeComponent(std::shared_ptr<EntityComponent>& component);

            /** @brief gets a component from the entity
             *
             * @tparam Component the component type to get
             * @return a pointer to the component
             *
             * @throws ComponentNotFound if a component of type Component is not a part of the entity
             */
            template <typename Component>
            std::shared_ptr<Component> get()
            {
                const std::type_index index(typeid(Component));
                auto itr = mComponents.find(index);
                if(itr == mComponents.end())
                {
                    BOOST_THROW_EXCEPTION(ComponentNotFound() << ComponentType(index));
                }
                return std::dynamic_pointer_cast<Component>(itr->second);
            }

        private:
            std::unordered_map<std::type_index, std::shared_ptr<EntityComponent>> mComponents;
        };
    }
}


#endif //DUNGEONENGINE_ENTITY_H
