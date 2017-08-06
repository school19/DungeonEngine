set(SERVER_SOURCES main.cpp server.cpp server.h router.cpp router.h)

find_package(Boost REQUIRED system program_options iostreams)

add_executable(server ${SERVER_SOURCES})

target_include_directories(server PUBLIC ${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})
target_link_libraries(server ${Boost_LIBRARIES})

if(POSIX)
    target_link_libraries(server pthread)
elseif(WIN32)
    add_definitions(-DBOOST_ALL_NO_LIB)
endif()