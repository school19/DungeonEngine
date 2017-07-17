//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_INVENTORY_H
#define DUNGEONENGINE_INVENTORY_H


#include <vector>

class Inventory {
public:
    Inventory();
    ~Inventory();

private:
    int mPlatinum;
    int mGold;
    int mElectrum;
    int mSilver;
    int mCopper;

    std::vector<> mContents;
};


#endif //DUNGEONENGINE_INVENTORY_H
