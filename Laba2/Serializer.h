#pragma once

#include <iostream>
#include <string>
#include <fstream>

template<typename T>
class Serializer
{
public:
	Serializer() = default;
	Serializer(std::string path);

	std::string getPath();

	void sterilize(T item);
	T deserialize();

private:
	std::string path;
};
