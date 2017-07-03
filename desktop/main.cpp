#include <QApplication>
#include "../engine/DungeonEngine.h"
#include "QtUiProviderImplFactory.h"
#include "QtWindowImpl.h"

int main(int argc, const char* argv[])
{
    DungeonEngine engine(argc, const_cast<char**>(argv));
    return app.exec();
}