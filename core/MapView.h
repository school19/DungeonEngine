//
// Created by Chaz on 9/12/2017.
//

#ifndef DUNGEONENGINE_MAPVIEW_H
#define DUNGEONENGINE_MAPVIEW_H


#include "Map.h"
#include "Utility.h"

namespace core{
class MapView {
public:
    MapView(std::shared_ptr<Map> map);
    virtual ~MapView();

private:
    utility::Point offset;

};
}

#endif //DUNGEONENGINE_MAPVIEW_H
