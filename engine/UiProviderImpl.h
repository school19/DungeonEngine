//
// Created by Chaz on 6/27/2017.
//

#ifndef DUNGEONENGINE_UIPROVIDERIMPL_H
#define DUNGEONENGINE_UIPROVIDERIMPL_H

#include <memory>
#include "Label.h"

class UiProviderImpl{
protected:
    UiProviderImpl()= default;
public:
    virtual ~UiProviderImpl() = default;

    virtual std::shared_ptr<Label> createLabel() = 0;
    
};

#endif //DUNGEONENGINE_UIPROVIDERIMPL_H
