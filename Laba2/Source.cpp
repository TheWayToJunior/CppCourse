#include <iostream>
#include <iomanip>
#include "Vector.cpp"
#include "Matrix.cpp"
#include "Fraction.h"

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

	/*	Задание 1

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

	std::cout << "Task 1: " << std::endl << std::endl;

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

	std::cout << std::endl;

	/*	Задание 2

		Написать класс Fraction для представления обыкновенных дробей (как отношения
		двух целых чисел x/y). Перегрузить операторы +, -, *, / для дробей. Реализовать метод
		void reduce() для сокращения дроби, а также статические методы:
			- int gcd(int n, int m)
			функция для нахождения наибольшего общего делителя чисел n и m;
			- void printAsFraction(double decimal_fraction)
			- void printAsFraction(char* decimal_fraction)
			перегруженные методы вывода десятичной дроби в виде обыкновенной
			(например, при значении decimal_fraction = 0.43 на экране должно
			вывестись 43/100, при 0.25 – 1/4 и т.д.).

		Также реализовать в виде статического члена класса счетчик всех созданных на
		данный момент в программе экземпляров дробей.
		Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
		Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
		на экран результаты. Показать также результаты работы статических методов класса.

	*/

	std::cout << std::endl << "Task 2: " << std::endl;

	Fraction f1(10, 20);
	f1.reduce();

	Fraction f2(2, 2);
	f2.reduce();

	std::cout << f1 + f2 << std::endl;

	char d[] = "1/4";

	Fraction::printAsFraction(d);
	Fraction::printAsFraction(0.25);

	int gcd = Fraction::gcd(11, 12);

	std::cout << Fraction::getCount() << std::endl;

	/*	Задание 3



	*/

	return 0;
}
