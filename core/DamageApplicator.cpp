//
// Created by Chaz on 8/31/2017.
//

#include "DamageApplicator.h"
#include "HealthComponent.h"

namespace core{
    namespace entity{

        void DamageApplicator::apply(std::shared_ptr<Entity> &e) {
            std::shared_ptr<HealthComponent> health;
            try{
                health = e->get<HealthComponent>();

                auto current_health = health->getCurrentHealth();

                //TODO: check resistances and immunities once implemented

                current_health -= mAmount;

                health->setCurrentHealth(current_health);

                //TODO: notify rules engine that health changed

            }
            catch(ComponentNotFound& err)
            {
                //Log and rethrow
                throw err;
            }
        }
    }
}