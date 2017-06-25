#pragma once
#include <string>
#include <vector>

#include "Ruleset.h"
#include "ErrorListener.h"
#include "Ruleset.h"

class DungeonEngine {
private:
	std::string mBaseDir;
	ErrorListener* mErrorListener = nullptr;

public:
	DungeonEngine() = delete;
	DungeonEngine(std::string baseDir);
	~DungeonEngine() = default;

	void setErrorListener(ErrorListener* listener);

	std::vector<Ruleset> getRulesets();
};