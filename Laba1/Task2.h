#pragma once

#include <iostream>
#include <iomanip>

/* Задание 2

2D -> 1D. Двумерный массив 5х5 целых чисел необходимо выложить
в один ряд по элементам слева направо и сверху вниз, исключая все элементы на
четных строках.

Инициализация: заполнить массив факториалами: x[i][j] = ( i+j )! .

Вывод на экран: на каждый элемент массива отвести 8 позиций.

*/

class Task2 
{
public:
	void run()
	{
		setlocale(LC_ALL, "rus");

		int row = 5, cell = 5;

		int** tdArr = getTdArr(row, cell);

		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < cell; j++)
			{
				std::cout << std::setw(8) << *(*(tdArr + i) + j);
			}

			std::cout << std::endl;
		}

		int* toArr = convert(tdArr, row, cell, 15);

		std::cout << std::endl;

		for (size_t i = 0; i < 15; i++)
		{
			std::cout << *(toArr + i) << std::setw(8);
		}

		std::cout << std::endl;

		for (size_t i = 0; i < row; i++)
		{
			delete[] tdArr[i];
		}

		delete[] tdArr;
		delete[] toArr;
	}

private:
	int getFactorial(int value)
	{
		if (value == 1 || value == 0)
			return 1;

		return value * getFactorial(value - 1);
	}

	int** getTdArr(int sizeRow, int sizeCell)
	{
		int** tdArr = new int* [sizeRow];

		for (size_t i = 0; i < sizeRow; i++)
		{
			*(tdArr + i) = new int[sizeCell];
		}

		for (size_t i = 0; i < sizeRow; i++)
		{
			for (size_t j = 0; j < sizeCell; j++)
			{
				*(*(tdArr + i) + j) = getFactorial(i + j);
			}
		}

		return tdArr;
	}

	int* convert(int** tdArr, int sizeRow, int sizeCell, int newSizeArr)
	{
		// TODO : Ñalculate the number of even numbers
		int* odArr = new int[newSizeArr];

		for (size_t i = 0, k = 0; i < sizeRow; i++)
		{
			for (size_t j = 0; j < sizeCell; j++)
			{
				if ((i + 1) % 2 != 0)
				{
					*(odArr + k) = *(*(tdArr + i) + j);
					k++;
				}
			}
		}

		return odArr;
	}
};
