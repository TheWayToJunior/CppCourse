#pragma once
#include <string>

class ILoggable 
{
public:
	virtual ~ILoggable() {};

	virtual void logToScreen() = 0;
	virtual void logToFile(const std::string& fileName) = 0;
};