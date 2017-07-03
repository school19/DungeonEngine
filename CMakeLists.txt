cmake_minimum_required(VERSION 3.4.1)

project(DungeonEngine C CXX)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lua)
add_subdirectory(engine)
add_subdirectory(desktop)