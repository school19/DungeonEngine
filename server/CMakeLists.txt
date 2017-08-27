set(SERVER_SOURCES main.cpp server.cpp server.h )

add_executable(server ${SERVER_SOURCES})

if(POSIX)
    target_link_libraries(server pthread)
elseif(WIN32)
    add_definitions(-DBOOST_ALL_NO_LIB -DBOOST_ALL_DYN_LINK)
endif()