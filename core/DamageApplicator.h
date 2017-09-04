//
// Created by Chaz on 8/31/2017.
//

#ifndef DUNGEONENGINE_DAMAGEAPPLICATOR_H
#define DUNGEONENGINE_DAMAGEAPPLICATOR_H

#include "Constants.h"
#include "EntityOperation.h"

namespace core{
    namespace entity{
        class DamageApplicator : public EntityOperation {
        public:
            DamageApplicator() = default;
            ~DamageApplicator() = default;

            virtual void apply(std::shared_ptr<Entity>& e) override;

        private:
            core::rules::DamageType  mDamageType;
            unsigned int mAmount;
        };
    }
}


#endif //DUNGEONENGINE_DAMAGEAPPLICATOR_H
