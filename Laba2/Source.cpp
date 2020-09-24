#include <iostream>
#include <iomanip>
#include "Vector.cpp"
#include "Matrix.cpp"

/* Задание 1

	Написать классы Vector и Matrix для хранения и обработки одномерных и
	двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
	с помощью созданных классов. Все функции оформить в виде методов классов.

	Задание 2 лабораторной работы №1:

	2D -> 1D. Двумерный массив 5х5 целых чисел необходимо выложить
	в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
	четных строках.

	Инициализация: заполнить массив факториалами: x[i][j] = ( i+j )! .

	Вывод на экран: на каждый элемент массива отвести 8 позиций.

*/

int getFactorial(int value)
{
	if (value == 1 || value == 0)
		return 1;

	return value * getFactorial(value - 1);
}

Matrix<int> getMatrix(int sizeRow, int sizeCell)
{
	Matrix<int> matrix(sizeRow, sizeCell);

	for (size_t i = 0; i < sizeRow; i++)
	{
		for (size_t j = 0; j < sizeCell; j++)
		{
			//matrix.setAt(i, j, getFactorial(i + j));
			matrix[i][j] = getFactorial(i + j);
		}
	}

	return matrix;
}

Vector<int> convert(const Matrix<int> matrix, int newSize)
{
	// TODO : Сalculate the number of even numbers
	Vector<int> vector(newSize);

	for (size_t i = 0, k = 0; i < matrix.getRows(); i++)
	{
		for (size_t j = 0; j < matrix.getCells(); j++)
		{
			if ((i + 1) % 2 != 0)
			{
				//vector[k] = matrix.at(i, j);
				vector[k] = matrix[i][j];
				k++;
			}
		}
	}

	return vector;
}

int main()
{
	int row = 5, cell = 5;

	Matrix<int> matrix = getMatrix(row, cell);

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < cell; j++)
		{
			std::cout << std::setw(8) << matrix[i][j]; // matrix.at(i, j)
		}

		std::cout << std::endl;
	}

	Vector<int> vector = convert(matrix, 15);

	std::cout << std::endl;

	for (size_t i = 0; i < 15; i++)
	{
		std::cout << vector[i] << std::setw(8);
	}

	return 0;
}
