//
// Created by Chaz on 8/25/2017.
//

#ifndef DUNGEONENGINE_HEALTHCOMPONENT_H
#define DUNGEONENGINE_HEALTHCOMPONENT_H


#include "EntityComponent.h"

class HealthComponent: public EntityComponent {
public:

private:
    int mMaxHealth;
    int mCurrentHealth;
};


#endif //DUNGEONENGINE_HEALTHCOMPONENT_H
