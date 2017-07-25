cmake_minimum_required(VERSION 3.4.1)

project(DungeonEngine C CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(RapidJson REQUIRED)

add_subdirectory(engine)

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()