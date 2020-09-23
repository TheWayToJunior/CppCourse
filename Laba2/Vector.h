#pragma once

template<typename T>
class Vector
{
public: 
	Vector(int size);
	Vector(const Vector<T>& oldVector);
	~Vector();

	int getSize();

	T& operator[](int i) const;

	Vector<T>& operator++(void);
	Vector<T> operator++(int);
	Vector<T>& operator--(void);
	Vector<T> operator--(int);

private:
	int size;
	T* sourceArray;

	void incrementedArray();
	void decrementedArray();
};