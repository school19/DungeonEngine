//
// Created by Chaz on 6/28/2017.
//

#ifndef DUNGEONENGINE_LABEL_H
#define DUNGEONENGINE_LABEL_H


#include "LabelImpl.h"

class Label {
public:
    Label(std::unique_ptr<LabelImpl> impl);
    ~Label();
};


#endif //DUNGEONENGINE_LABEL_H
