#pragma once
#include "Vector.h"

template<typename T>
class Matrix
{
public:
	Matrix(int rows, int cells);
	Matrix(const Matrix<T>& oldMatrix);
	~Matrix();

	static Matrix<int> getMatrix(int sizeRow, int sizeCell);
	Vector<int> convert(int newSize);

	int getRows() const;
	int getCells() const;
	T at(int i, int j) const;
	void setAt(int i, int j, T value);

	T*& operator[](int i) const;

	Matrix<T>& operator++(void);
	Matrix<T> operator++(int);
	Matrix<T>& operator--(void);
	Matrix<T> operator--(int);

private:
	T** sourceMatrix;
	int rows;
	int cells;

	static int getFactorial(int value);
	void incrementedArray();
	void decrementedArray();

	T** createMatrix(int rows, int cells);
};

