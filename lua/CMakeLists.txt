cmake_minimum_required(VERSION 3.4.1)

set(LUALIB_SRC lapi.c lauxlib.c lbaselib.c lbitlib.c lcode.c lcorolib.c lctype.c ldblib.c ldebug.c ldo.c ldump.c lfunc.c lgc.c linit.c liolib.c llex.c lmathlib.c lmem.c loadlib.c lobject.c lopcodes.c loslib.c lparser.c lstate.c lstring.c lstrlib.c ltable.c ltablib.c ltm.c lundump.c lutf8lib.c lvm.c lzio.c)

add_library(lualib STATIC ${LUALIB_SRC})

set_target_properties(lualib PROPERTIES DEFINE_SYMBOL "LUA_BUILD_AS_DLL")
set_target_properties(lualib PROPERTIES LINKER_LANGUAGE C)
set_target_properties(lualib PROPERTIES LIBRARY_NAME "lua")

install(TARGETS lualib DESTINATION lib/lua.lib EXPORT lualib-target)
install(EXPORT lualib-target DESTINATION lib)

add_executable(lua lua.c ${LUALIB_SRC})
set_target_properties(lua PROPERTIES LINKER_LANGUAGE C)

add_executable(luac luac.c ${LUALIB_SRC})
set_target_properties(luac PROPERTIES LINKER_LANGUAGE C)

