cmake_minimum_required(VERSION 3.4.1)

if(WIN32)
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_library(lualib
			SHARED
			lapi.c
			lauxlib.c
			lbaselib.c
			lbitlib.c
			lcode.c
			lcorolib.c
			lctype.c
			ldblib.c
			ldebug.c
			ldo.c
			ldump.c
			lfunc.c
			lgc.c
			linit.c
			liolib.c
			llex.c
			lmathlib.c
			lmem.c
			loadlib.c
			lobject.c
			lopcodes.c
			loslib.c
			lparser.c
			lstate.c
			lstring.c
			lstrlib.c
			ltable.c
			ltablib.c
			ltm.c
			lundump.c
			lutf8lib.c
			lvm.c
			lzio.c)
			
set_target_properties(lualib PROPERTIES OUTPUT_NAME "lua")
			
add_executable(lua lua.c)
target_link_libraries(lua lualib)
if(UNIX)
	target_link_libraries(lua m)
endif()

add_executable(luac luac.c)
target_link_libraries(luac lualib)
if(UNIX)
	target_link_libraries(luac m)
endif()