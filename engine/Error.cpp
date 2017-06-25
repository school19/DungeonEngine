#include "Error.h"
#include <lua.hpp>

std::string luaTypeName(int type)
{
	switch (type)
	{
	default:
		return "unkown type";
	case LUA_TNIL:
		return "nil";
	case LUA_TNUMBER:
		return "number";
	case LUA_TTABLE:
		return "table";
	case LUA_TFUNCTION:
		return "function";
	case LUA_TBOOLEAN:
		return "boolean";
	case LUA_TLIGHTUSERDATA:
		return "light user data";
	case LUA_TUSERDATA:
		return "user data";
	case LUA_TTHREAD:
		return "thread";
	}
}