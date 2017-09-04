//
// Created by Chaz on 8/23/2017.
//

#ifndef DUNGEONENGINE_ENTITYCOMPONENT_H
#define DUNGEONENGINE_ENTITYCOMPONENT_H


namespace core{
    namespace entity{
        class EntityComponent {
        protected:
            EntityComponent() = default;
        public:
            virtual ~EntityComponent() = default;

        };
    }
}


#endif //DUNGEONENGINE_ENTITYCOMPONENT_H
