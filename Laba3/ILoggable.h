#pragma once
#include <string>

class ILoggable 
{
public:
	virtual ~ILoggable() {};

	void virtual logToScreen() = 0;
	void virtual logToFile(const std::string& fileName) = 0;
};