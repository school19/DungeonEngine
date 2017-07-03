//
// Created by Chaz on 7/1/2017.
//

#ifndef DUNGEONENGINE_QTUIPROVIDERIMPLFACTORY_H
#define DUNGEONENGINE_QTUIPROVIDERIMPLFACTORY_H


#include <QtWidgets/qwidget.h>
#include "../engine/UiProviderImplFactory.h"

class QtUiProviderImplFactory : public UiProviderImplFactory{
private:
public:
    QtUiProviderImplFactory() = default;
    virtual ~QtUiProviderImplFactory() = default;

    std::unique_ptr<UiProviderImpl> create() override;
};


#endif //DUNGEONENGINE_QTUIPROVIDERIMPLFACTORY_H
