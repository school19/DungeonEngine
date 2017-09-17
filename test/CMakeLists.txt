set(TEST_SOURCES EntityTest.cpp main.cpp ../application/main.cpp)

add_executable(dungeon_engine_test ${TEST_SOURCES})

target_link_libraries(dungeon_engine_test core)
target_include_directories(dungeon_engine_test PUBLIC ../core)