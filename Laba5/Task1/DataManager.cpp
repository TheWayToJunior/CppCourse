#include "DataManager.h"

template<class T>
DataManager<T>::DataManager()
{
}

template<class T>
void DataManager<T>::push(T value)
{
	if (max_size <= data.size())
	{
		this->ofstream();
		data.clear();
	}

	this->data.push_front(T);
}

template<class T>
void DataManager<T>::push(T values[], size_t size)
{
	if (max_size - data.size() > size)
	{
		this->ofstream();
		data.clear();
	}

	for (size_t i = 0; i < size; i++)
	{
		this->data.push_front(values[i]);
	}
}

template<class T>
T DataManager<T>::peek()
{
	return data.size() < 2 ? 0 : *++data.begin();
}

template<class T>
T DataManager<T>::pop()
{
	auto temp = data.back();
	data.remove(temp);

	return temp;
}

template<class T>
void DataManager<T>::ofstream()
{
	std::ofstream out;
	out.open("dump.dat", std::ios::app | std::ios::out);

	if (out.is_open())
	{
		for (auto value : data)
		{
			out << value << std::endl;
		}
	}
}

