#pragma once
#include <string>
#include<vector>

template <class T>
class Cache
{
public:
	std::vector<T> mass;
	void put(T elem)
	{
		mass.push_back(elem);
	}
	void operator+= (T elem)
	{
		mass.push_back(elem);
	}
	bool contains(T elem)
	{
		for (int i = 0; i < mass.size(); i++)
		{
			if (mass[i] == elem)
			{
				return true;
			}
		}
		return false;
	}
};

template <>
class Cache<std::string>
{
	std::vector<std::string> mass;

public:
	void put(std::string elem)
	{
		mass.push_back(elem);
	}

	bool contains(std::string elem)
	{
		for (int i = 0; i < mass.size(); i++)
		{
			if (mass[0] == elem)
			{
				return true;
			}
		}
		return false;
	}
	void add()
	{
		if (mass.size() > 100)
		{
			throw;
		}
	}
};