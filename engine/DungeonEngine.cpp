#include "DungeonEngine.h"
#include "Error.h"
#include <boost/filesystem.hpp>
#include <lua.hpp>

const std::string RulesetFileName = "base.lua";
const std::string RulesetNameField = "name";

DungeonEngine::DungeonEngine(std::string baseDir)
{
	mBaseDir = baseDir;
}

std::vector<Ruleset> DungeonEngine::getRulesets()
{
	using namespace boost;
	using namespace boost::filesystem;

	path p(mBaseDir);

	if (!exists(p))
	{
		BOOST_THROW_EXCEPTION(file_not_found_error()
		<< errinfo_file_name(mBaseDir));
	}

	if (!is_directory(p))
	{
		BOOST_THROW_EXCEPTION(incorrect_file_type_error()
		<< errinfo_file_name(mBaseDir));
	}

	std::vector<std::string> names;
	for (auto start = directory_iterator(p); start != directory_iterator(); start++)
	{
		auto base_lua = start->path() / RulesetFileName;
		if (exists(base_lua))
		{
			lua_State* L = luaL_newstate();
			luaL_openlibs(L);

			auto error = luaL_loadfile(L, base_lua.string().c_str());
			if (error != LUA_OK)
			{
				if (mErrorListener != nullptr)
				{
					mErrorListener->onError(std::string(lua_tostring(L, -1)));
				}
				lua_close(L);
				continue;
			}

			error = lua_pcall(L, 0, 1, 0);
			if (error != LUA_OK)
			{
				if (mErrorListener != nullptr)
				{
					mErrorListener->onError(std::string(lua_tostring(L, -1)));
				}
				lua_close(L);
				continue;
			}

			if (lua_type(L, -1) != LUA_TTABLE)
			{
				if (mErrorListener != nullptr)
				{
					std::ostringstream msg;
					msg << base_lua.string()
						<< ": Expected return value of type table (got "
						<< luaTypeName(lua_type(L, -1))
						<< " instead)";
					mErrorListener->onError(msg.str());
				}
				lua_close(L);
				continue;
			}

			auto type = lua_getfield(L, -1, RulesetNameField.c_str());
			if (type != LUA_TSTRING)
			{
				if (mErrorListener != nullptr)
				{
					std::ostringstream msg;
					msg << base_lua.string()
						<< ": Expected return value of type string (got "
						<< luaTypeName(lua_type(L, -1))
						<< " instead)";
					mErrorListener->onError(msg.str());
				}
				lua_close(L);
				continue;
			}

			names.push_back(std::string(lua_tostring(L, -1)));
		}
	}
	return std::vector<Ruleset>();
}

void DungeonEngine::setErrorListener(ErrorListener* listener)
{
	mErrorListener = listener;
}