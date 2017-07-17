//
// Created by Chaz on 7/13/2017.
//

#ifndef DUNGEONENGINE_ITEMENTRY_H
#define DUNGEONENGINE_ITEMENTRY_H


#include <memory>
#include "Item.h"

class ItemEntry {
public:
    ItemEntry();
    ~ItemEntry();

    class Builder;

private:
    std::shared_ptr<Item> mItem;
    int mQuantity;
    bool mEquiped;
};

class ItemEntry::Builder
{

};
#endif //DUNGEONENGINE_ITEMENTRY_H
