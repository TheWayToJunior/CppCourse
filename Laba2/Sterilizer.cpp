#include "Sterilizer.h"

template<typename T>
Sterilizer<T>::Sterilizer(std::string path)
	: path(path)
{
}

template<typename T>
std::string Sterilizer<T>::getPath()
{
	return this->path;
}

template<typename T>
void Sterilizer<T>::sterilize(T item)
{
	std::ofstream fout;

	try
	{
		fout.open(this->path);
		fout.write((char*)&item, sizeof(T));
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	fout.close();
}

template<typename T>
T Sterilizer<T>::deserialize()
{
	std::ifstream fin;
	T item;

	try
	{
		fin.open(this->path);

		fin.read((char*)&item, sizeof(T));
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	fin.close();

	return item;
}
