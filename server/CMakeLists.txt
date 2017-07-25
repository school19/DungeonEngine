set(SERVER_SOURCES main.cpp HttpConnection.cpp HttpConnection.h ApiServer.cpp ApiServer.h HttpHeader.cpp HttpHeader.h HttpRequest.cpp HttpRequest.h HttpResponse.cpp HttpResponse.h)

find_package(Boost REQUIRED)

add_executable(server ${SERVER_SOURCES})

target_include_directories(server PUBLIC ${Boost_INCLUDE_DIR})