#include "Ruleset.h"
#include "Error.h"

Ruleset::Ruleset(std::string source_path): mSourcePath(source_path)
{
    mState = luaL_newstate();
    if(mState == nullptr)
    {
        throw std::bad_alloc();
    }

    luaL_openlibs(mState);
}

Ruleset::~Ruleset()
{
    if(mState != nullptr)
    {
        lua_close(mState);
    }
}

void Ruleset::evaluate() {
    if(mEvaluated) {
        return;
    }

    auto result = luaL_loadfile(mState, mSourcePath.c_str());
    if(result != LUA_OK)
    {
        reportError(lua_tostring(mState, -1));
        lua_pop(mState, 1);
        return;
    }

    result = lua_pcall(mState, 0, 1, 0);
    if(result != LUA_OK)
    {
        reportError(lua_tostring(mState, -1));
        lua_pop(mState, 1);
        return;
    }

    //the ruleset lua file should return a single table
    auto type = lua_type(mState, -1);
    if(type != LUA_TTABLE)
    {
        std::ostringstream msg;
        msg << "Ruleset definition '"
            << mSourcePath
            << "' does not return a table object";
        reportError(msg.str());
        return;
    }

    //save the ruleset table so nothing overwrites the variable name (also so we don't have to care what the name is)
    mTableIndex = luaL_ref(mState, -1);
    
    mEvaluated = true;
}

void Ruleset::setErrorListener(ErrorListener *errorListener) {
    mErrorListener = errorListener;
}

void Ruleset::reportError(std::string error_msg) {
    if(mErrorListener != nullptr)
    {
        mErrorListener->onError(error_msg);
    }
}