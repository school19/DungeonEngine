#pragma once
#include <string>

class ErrorListener
{
public:
	virtual void onError(std::string msg) = 0;
};