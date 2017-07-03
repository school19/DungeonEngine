//
// Created by Chaz on 6/27/2017.
//

#ifndef DUNGEONENGINE_MAINWINDOW_H
#define DUNGEONENGINE_MAINWINDOW_H

#include <QMainWindow>
#include "../engine/WindowImpl.h"

class QtWindowImpl : public QMainWindow, public WindowImpl{
public:
    QtWindowImpl();
    virtual ~QtWindowImpl();
};


#endif //DUNGEONENGINE_MAINWINDOW_H
