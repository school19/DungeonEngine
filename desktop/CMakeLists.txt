cmake_minimum_required(VERSION 3.4.1)

set(CMAKE_INCLUDE_CURRENT_DIR  ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set(APP_SOURCES main.cpp QtWindowImpl.cpp QtWindowImpl.h QtUiProviderImpl.cpp QtUiProviderImpl.h QtUiProviderImplFactory.h QtUiProviderImplFactory.cpp QtLabelImpl.cpp QtLabelImpl.h)

if(WIN32)
    add_executable(DungeonCompanion WIN32 ${APP_SOURCES})
    target_link_libraries(DungeonCompanion runtimeobject)
else()
    add_executable(DungeonCompanion ${APP_SOURCES})
endif()

target_include_directories(DungeonCompanion PUBLIC ${Qt5Widgets_INCLUDE_DIRS} engine)
target_link_libraries(DungeonCompanion Qt5::Widgets)

