#include "Vector.h"

template<typename T>
Vector<T>::Vector(int size)
{
	this->size = size;
	this->sourceArray = new T[size];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& oldVector)
{
	this->size = oldVector.size;
	this->sourceArray = new T[size];

	for (size_t i = 0; i < size; i++)
	{
		this->sourceArray[i] = oldVector.sourceArray[i];
	}
}

template<typename T>
Vector<T>::~Vector()
{
	delete[] this->sourceArray;
}

template<typename T>
int Vector<T>::getSize()
{
	return this->size;
}

template<typename T>
T& Vector<T>::operator[](int i) const
{
	return this->sourceArray[i];
}

template<typename T>
Vector<T>& Vector<T>::operator++(void)
{
	this->incrementedArray();

	return *this;
}

template<typename T>
Vector<T>& Vector<T>::operator--(void)
{
	this->decrementedArray();

	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator++(int)
{
	Vector<T> oldVector(*this);

	this->incrementedArray();

	return oldVector;
}

template<typename T>
Vector<T> Vector<T>::operator--(int)
{
	Vector<T> oldVector(*this);

	this->decrementedArray();

	return oldVector;
}

template<typename T>
void Vector<T>::incrementedArray()
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->sourceArray[i]++;
	}
}

template<typename T>
void Vector<T>::decrementedArray()
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->sourceArray[i]--;
	}
}
