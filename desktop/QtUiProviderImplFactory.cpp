//
// Created by Chaz on 7/1/2017.
//

#include "QtUiProviderImplFactory.h"
#include "QtUiProviderImpl.h"

std::unique_ptr<UiProviderImpl> QtUiProviderImplFactory::create() {
    return std::make_unique<QtUiProviderImpl>();
}
