#pragma once

template<typename T>
class Matrix
{
public:
	Matrix(int rows, int cells);
	Matrix(const Matrix<T>& oldMatrix);
	~Matrix();

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

	void incrementedArray();
	void decrementedArray();

	T** createMatrix(int rows, int cells);
};

