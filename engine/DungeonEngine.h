#pragma once
#include <string>
#include <vector>

#include "Ruleset.h"
#include "ErrorListener.h"
#include "Ruleset.h"
#include "UiProviderImplFactory.h"

class DungeonEngine {
private:
	std::string mBaseDir;
	ErrorListener* mErrorListener = nullptr;
    std::unique_ptr<UiProviderImplFactory> mUiImplFactory = nullptr;

public:
	DungeonEngine() = delete;
	DungeonEngine(int argc, char **argv);
	~DungeonEngine() = default;

	void setErrorListener(ErrorListener* listener);

	std::vector<Ruleset> getRulesets();
};