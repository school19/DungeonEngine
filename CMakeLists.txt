cmake_minimum_required(VERSION 3.4.1)

project(DungeonEngine C CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED system program_options iostreams)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
link_libraries(${Boost_LIBRARIES})

add_subdirectory(core)
add_subdirectory(server)
add_subdirectory(test)

get_cmake_property(_variableNames VARIABLES)
foreach (_variableName ${_variableNames})
    message(STATUS "${_variableName}=${${_variableName}}")
endforeach()