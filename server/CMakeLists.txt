set(SERVER_SOURCES main.cpp HttpConnection.cpp HttpConnection.h HttpServer.cpp HttpServer.h HttpHeader.h HttpRequest.h HttpResponse.h ConnectionManager.cpp ConnectionManager.h RequestParser.cpp RequestParser.h HttpRequest.cpp Router.cpp Router.h Route.cpp Route.h)

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