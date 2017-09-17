//
// Created by Chaz on 9/11/2017.
//

#ifndef DUNGEONENGINE_MAPWIDGET_H
#define DUNGEONENGINE_MAPWIDGET_H

#include <memory>
#include <QtWidgets/QTabWidget>
#include "../core/MapView.h"

class MapWidget : public QWidget, public core::MapView {
    Q_OBJECT
public:
    MapWidget(QWidget* parent = 0);
    ~MapWidget();

    void setMap(std::shared_ptr<core::MapView> mapView);

private:


};


#endif //DUNGEONENGINE_MAPWIDGET_H
