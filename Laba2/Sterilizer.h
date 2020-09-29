#pragma once

#include <iostream>
#include <string>
#include <fstream>

template<typename T>
class Sterilizer
{
public:
	Sterilizer() = default;
	Sterilizer(std::string path);

	std::string getPath();

	void sterilize(T item);
	T deserialize();

private:
	std::string path;
};
