cmake_minimum_required(VERSION 3.4.1)

project(DungeonEngine C CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Boost 1.65.1 REQUIRED system program_options iostreams)
find_package(Qt5 REQUIRED Widgets Core Gui)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
link_libraries(${Boost_LIBRARIES} Qt5::Widgets Qt5::Core Qt5::Gui)

add_subdirectory(core)
add_subdirectory(server)
add_subdirectory(test)
add_subdirectory(application)

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()