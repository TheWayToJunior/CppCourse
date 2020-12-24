#pragma once
#include <list>
#include <iterator>
#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>

template<class T>
class DataManager
{
public:
	DataManager();
	void push(T value);
	void push(T values[], size_t size);
	T peek();
	T pop();
	void ofstream();

private:
	std::list<T> data;
	int max_size = 64;
};

template <>
class DataManager<char>
{
private:
	char mass_p[10] = { ',',';',':','.', '?', '!', '-', '(', ')', '"' };
	std::vector<char> data;
public:
	void push(char temp)
	{
		data.push_back(temp);

		if (scan(data[data.size()]))
		{
			data[data.size()] = '_';
		}
	}

	char popUpper()
	{
		return static_cast<char>(std::toupper(*data.rbegin()));
	}

	char popLower()
	{
		return static_cast<char>(std::tolower(*data.rbegin()));
	}

	bool scan(char item)
	{
		for (int i = 0; i < 10; i++)
		{
			if (item == mass_p[i])
				return true;
		}

		return false;
	}
};

