#pragma once

#include <memory>
#include <Math.h>
#include "ItemSharedArray.h"
#include <time.h>

#define SHPTR_TARR std::shared_ptr<T[]>

template<typename T>
class SharedArray
{
public:
	SharedArray(int size);

	ItemSharedArray<T> getMaxObject();
	int getSize();
	void generateValueArray(T beginValue, T endValue);

	T& operator [](size_t i) const;

private:
	int size;
	SHPTR_TARR arrSptr;
};

template<typename T>
SharedArray<T>::SharedArray(int size)
{
	this->size = size;
	this->arrSptr = std::shared_ptr<T[]>(new T[size]);
}

template<typename T>
ItemSharedArray<T> SharedArray<T>::getMaxObject()
{
	T max = NULL;
	int position = NULL;

	for (size_t i = 0; i < size; i++)
	{
		auto item = abs(arrSptr[i]);

		if (item > max)
		{
			max = item;
			position = i;
		}
	}

	return ItemSharedArray<T>(max, position);
}

template<typename T>
int SharedArray<T>::getSize()
{
	return this->size;
}

template<typename T>
void SharedArray<T>::generateValueArray(T beginValue, T endValue)
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		int randValue = rand() % (int)endValue + (int)beginValue;
		this->arrSptr[i] = (T)randValue;
	}
}

template<typename T>
T& SharedArray<T>::operator[](size_t i) const
{
	return this->arrSptr[i];
}