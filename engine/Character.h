//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_CHARACTER_H
#define DUNGEONENGINE_CHARACTER_H


#include <memory>
#include <vector>
#include <

#include "RaceInstance.h"
#include "CharacterClassInstance.h"
#include "CharacterState.h"

class Character {
public:
    Character();
    ~Character();

private:

    int mStrength;
    int mDexterity;
    int mConstitution;
    int mIntelligence;
    int mWisdom;
    int mCharisma;

    std::unique_ptr<RaceInstance> mRace;
    std::vector<CharacterClassInstance> mCharacterClasses; //most often this will only contain one element, but supporting multiclassing is important

};


#endif //DUNGEONENGINE_CHARACTER_H
