//
// Created by Chaz on 8/20/2017.
//

#ifndef DUNGEONENGINE_CHARACTER_H
#define DUNGEONENGINE_CHARACTER_H


class PlayerCharacter {
public:
    PlayerCharacter();
    ~PlayerCharacter();

private:

    int mStrengthScore;
    int mDexterityScore;
    int mConstitutionScore;
    int mIntelligenceScore;
    int mWisdomScore;
    int mCharismaScore;
};


#endif //DUNGEONENGINE_CHARACTER_H
