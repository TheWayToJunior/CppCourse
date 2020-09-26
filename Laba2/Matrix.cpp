#include "Matrix.h"

template<typename T>
T** Matrix<T>::createMatrix(int rows, int cells)
{
	T** matrix = new T*[rows];

	for (size_t i = 0; i < rows; i++)
	{
		matrix[i] = new T[cells];
	}

	return matrix;
}

template<typename T>
Matrix<T>::Matrix(int rows, int cells)
{
	this->rows = rows;
	this->cells = cells;
	this->sourceMatrix = createMatrix(rows, cells);
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T>& oldMatrix)
{
	this->rows = oldMatrix.rows;
	this->cells = oldMatrix.cells;
	this->sourceMatrix = createMatrix(rows, cells);

	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cells; j++)
		{
			this->sourceMatrix[i][j] = oldMatrix.sourceMatrix[i][j];
		}
	}
}

template<typename T>
Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		delete[] this->sourceMatrix[i];
	}

	delete[] this->sourceMatrix;
}

template<typename T>
int Matrix<T>::getRows() const
{
	return this->rows;
}

template<typename T>
int Matrix<T>::getCells() const
{
	return this->cells;
}

template<typename T>
T Matrix<T>::at(int i, int j) const
{
	return sourceMatrix[i][j];
}

template<typename T>
void Matrix<T>::setAt(int i, int j, T value)
{
	sourceMatrix[i][j] = value;
}

template<typename T>
T*& Matrix<T>::operator[](int i) const
{
	return this->sourceMatrix[i];
}

template<typename T>
Matrix<T>& Matrix<T>::operator++(void)
{
	this->incrementedArray();

	return *this;
}

template<typename T>
Matrix<T>& Matrix<T>::operator--(void)
{
	this->decrementedArray();

	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator++(int)
{
	Matrix<T> oldMatrix(*this);

	this->incrementedArray();

	return oldMatrix;
}

template<typename T>
Matrix<T> Matrix<T>::operator--(int)
{
	Matrix<T> oldMatrix(*this);

	this->decrementedArray();

	return oldMatrix;
}

template<typename T>
void Matrix<T>::incrementedArray()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cells; j++)
		{
			this->sourceMatrix[i][j]++;
		}
	}
}

template<typename T>
void Matrix<T>::decrementedArray()
{
	for (size_t i = 0; i < this->rows; i++)
	{
		for (size_t j = 0; j < this->cells; j++)
		{
			this->sourceMatrix[i][j]--;
		}
	}
}
