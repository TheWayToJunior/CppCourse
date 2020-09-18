#pragma once

template <typename T>
struct ItemSharedArray
{
public:
	int pisition;
	T value;

	ItemSharedArray(T value, int pisition)
	{
		this->value = value;
		this->pisition = pisition;
	}
};
