//
// Created by Chaz on 7/1/2017.
//

#ifndef DUNGEONENGINE_QTUIPROVIDER_H
#define DUNGEONENGINE_QTUIPROVIDER_H
#include "../engine/UiProviderImpl.h"

class QtUiProviderImpl : public UiProviderImpl {
public:
    QtUiProviderImpl() = default;
    virtual ~QtUiProviderImpl() = default;

    virtual std::shared_ptr<Label> createLabel() override;
};


#endif //DUNGEONENGINE_QTUIPROVIDER_H
