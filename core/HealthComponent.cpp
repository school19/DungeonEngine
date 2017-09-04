//
// Created by Chaz on 8/25/2017.
//

#include "HealthComponent.h"

namespace core {
    namespace entity {

        int HealthComponent::getMaxHealth() const {
            return mMaxHealth;
        }

        void HealthComponent::setMaxHealth(int maxHealth) {
            mMaxHealth = mMaxHealth;
        }

        int HealthComponent::getCurrentHealth() const {
            return mCurrentHealth;
        }

        void HealthComponent::setCurrentHealth(int currentHealth) {
            mCurrentHealth = currentHealth;
        }

    }
}