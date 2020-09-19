#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdio.h>

/* Задание 1

	Объявите массив из n=20 действительных чисел, инициализируйте его нулями. Функция
	processArray () должен заполнить массив случайными числами от -20.0 до 70.0, а также
	затем добавьте массив, то есть разделите каждый элемент массива на максимальное значение
	по модулю значения в массиве. Он также должен возвращать это значение на выходе.
	Сгенерируйте выходной реальный массив, в котором все элементы, которые находятся до
	позиции максимального элемента включительно повторяют элементы входного сигнала
	массив, а остальные равны x (введите число x с помощью клавиатуры). Дисплей
	результирующий массив.

*/

template<typename T>
void print(T* sptr, int size, const char* format)
{
	for (size_t i = 0; i < size; i++)
	{
		printf(format, i, sptr[i]);
	}
}

float* processArray(int* mass, float valueX)
{
	srand(time(NULL));

	const int size = 20;

	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 70 + (-20);
	}

	std::cout << std::endl;

	print<int>(mass, size, "mass[%d] = %d\n");

	int positionMaxItem = NULL;
	int maxItem = NULL;

	for (size_t i = 0; i < size; i++)
	{
		auto item = abs(mass[i]);

		if (item > maxItem)
		{
			maxItem = item;
			positionMaxItem = i;
		}
	}

	std::cout << "\nmax: " << maxItem << "  position: " << positionMaxItem << "\n\n";

	float* massF = new float[size];

	for (int i = 0; i < size; i++)
	{
		if (positionMaxItem <= i)
			massF[i] = valueX;
		else
			massF[i] = (float)mass[i] / maxItem;
	}

	return massF;
}


/* Задание 2

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
	// TODO : Сalculate the number of even numbers
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


/* Задание 3

	Функция strcmp.
	Формат int strcmp(const char* s1, const char* s2).
	Функция сравнивает строку s1 со строкой s2 в лексикографическом порядке. Если s1<s2,
	то результат равен -1, если s1=s2, то 0, если s1>s2, то 1.

*/

int strnum(const char* string)
{
	int num = 0;

	while (*string)
	{
		num += *string++;
	}

	return num;
}

int my_strcmp(const char* string1, const char* string2)
{
	unsigned f = strnum(string1);
	unsigned l = strnum(string2);

	if (f == l)
		return 0;

	return f < l ? -1 : 1;
}


int main()
{
	std::cout << "Task1: " << std::endl;

	const int size = 20;
	int mass[size];

	float x = 0;
	scanf_s("%f", &x);

	float* massF = processArray(mass, x);

	print<float>(massF, size, "mass[%d] = %10.3f\n");

	delete[] massF;

	std::cout << "\nTask2: " << std::endl;

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

	std::cout << "\nTask3: " << std::endl;

	const char* string1 = "Hello";
	const char* string2 = "World";

	printf("string1 = %s\n", string1);
	printf("string2 = %s\n", string2);
	printf("\nmy result = %d\n", my_strcmp(string1, string2));
	printf("strcmp result = %d\n", std::strcmp(string1, string2));
}
