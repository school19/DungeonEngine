//
// Created by Chaz on 7/1/2017.
//

#ifndef DUNGEONENGINE_UIPROVIDERIMPLFACTORY_H
#define DUNGEONENGINE_UIPROVIDERIMPLFACTORY_H

#include "UiProviderImpl.h"

class UiProviderImplFactory{
protected:
    UiProviderImplFactory() = default;
public:
    virtual ~UiProviderImplFactory() = default;

    virtual std::unique_ptr<UiProviderImpl, std::default_delete<UiProviderImpl>> create() = 0;
};

#endif //DUNGEONENGINE_UIPROVIDERIMPLFACTORY_H
