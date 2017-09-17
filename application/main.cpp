//
// Created by Chaz on 9/9/2017.
//

#include <QApplication>
#include "MainWindow.h"

int main(int argc, const char* argv[])
{
    QApplication app(argc, const_cast<char**>(argv));

    MainWindow main_window;
    main_window.show();

    return app.exec();
}