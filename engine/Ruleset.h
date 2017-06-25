#pragma once

#include "ErrorListener.h"
#include <lua.hpp>

class Ruleset{
private:
    ErrorListener* mErrorListener;
    lua_State* mState;
    std::string mSourcePath;
    bool mEvaluated = false;
    int mTableIndex;

    void evaluate();
    void reportError(std::string error_msg);

public:
    Ruleset() = delete;
    Ruleset(const Ruleset&) = delete;
    ~Ruleset();

    Ruleset(std::string sourcePath);

    void setErrorListener(ErrorListener* errorListener);
};