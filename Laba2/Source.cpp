#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
#include "Vector.cpp"
#include "Matrix.cpp"
#include "Fraction.h"
#include "Shop.h"

int getFactorial(int value) {
	if (value == 1 || value == 0)
		return 1;

	return value * getFactorial(value - 1);
}

Matrix<int> getMatrix(int sizeRow, int sizeCell) {
	Matrix<int> matrix(sizeRow, sizeCell);

	for (size_t i = 0; i < sizeRow; i++) {
		for (size_t j = 0; j < sizeCell; j++) {
			//matrix.setAt(i, j, getFactorial(i + j));
			matrix[i][j] = getFactorial(i + j);
		}
	}

	return matrix;
}

Vector<int> convert(const Matrix<int> matrix, int newSize) {
	// TODO : Сalculate the number of even numbers
	Vector<int> vector(newSize);

	for (size_t i = 0, k = 0; i < matrix.getRows(); i++) {
		for (size_t j = 0; j < matrix.getCells(); j++) {
			if ((i + 1) % 2 != 0) {
				//vector[k] = matrix.at(i, j);
				vector[k] = matrix[i][j];
				k++;
			}
		}
	}

	return vector;
}

int main() {

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
	{
		int row = 5, cell = 5;

		Matrix<int> matrix = getMatrix(row, cell);

		for (size_t i = 0; i < row; i++) {
			for (size_t j = 0; j < cell; j++) {
				std::cout << std::setw(8) << matrix[i][j]; // matrix.at(i, j)
			}

			std::cout << std::endl;
		}

		Vector<int> vector = convert(matrix, 15);

		std::cout << std::endl;

		for (size_t i = 0; i < 15; i++) {
			std::cout << vector[i] << std::setw(8);
		}

		std::cout << std::endl;
	}

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
	{
		Fraction f1(10, 20);
		f1.reduce();

		Fraction f2(2, 2);
		f2.reduce();

		std::cout << f1 + f2 << std::endl;

		char d[] = "36/25";

		Fraction::printAsFraction(d);
		Fraction::printAsFraction(1.44);

		int gcd = Fraction::gcd(11, 12);

		std::cout << Fraction::getCount() << std::endl;
	}

	/*	Задание 3

		Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде
		инкапсуляцию данных, применение конструкторов без параметров и с параметрами
		для инициализации данных. Класс должен содержать метод serialize() для
		сохранения данных класса в файл и метод deserialize() для чтения данных класса
		из файла по умолчанию в текущей директории, а также перегруженные методы
		serialize(const std::string& filename) и deserialize(const std::string&
		filename) для работы с файлом с указанным в параметре именем.

		Вариант 2

		Класс МАГАЗИН.
		Данные: название, адрес, год основания, номер, суммарная прибыль.
		Создать два объекта-магазина в куче и один в стеке. Данные первых двух заполнить с
		помощью сеттеров, а третий проинициализировать с помощью конструктора с
		параметрами. В главной функции проимитировать отдельно продажи за сентябрь,
		октябрь и ноябрь. Вывести все магазины отдельно в двух рейтинговых списках (сначала
		один, затем второй): 1) отсортировать в порядке убывания общей прибыли за 3 месяца;
		2) отсортировать в порядке убывания среднего прироста прибыли за 3 месяца.

	*/

	std::cout << std::endl << "Task 3: " << std::endl;
	{
		setlocale(LC_ALL, "rus");

		enum Month {
			September = 9, October, November
		};

		// So beautiful but bad code )))
		void (*setProp)(Shop*, std::string, int) {
			[](Shop* obj, std::string value, int sumProfit) {
				obj->set_name("Shop №" + value);
				obj->set_address("Street " + value);
				obj->set_date(value + ".09.2016");
				obj->set_number(atoi(value.c_str()));
				obj->set_sumProfit(sumProfit);
			}
		};

		// Don't scold for STL
		double (*summ)(std::map<Month, double>&) {
			[](std::map<Month, double>& profit) {
				return profit[Month::September] +
					   profit[Month::October]   +
					   profit[Month::November];
			}
		};

		// It would be nice to encapsulate map in a class
		std::map<Month, double> profitShop1 = { 
			{ Month::September, 2500 }, 
			{ Month::October,   2355 }, 
			{ Month::November,  1725 } 
		};

		Shop s1("Shop №1", "Street 1", "1.03.2020", 1, summ(profitShop1));

		std::map<Month, double> profitShop2 = { 
			{ Month::September, 3200 },
			{ Month::October,   1525 },
			{ Month::November,  1812 } 
		};

		Shop* s2 = new Shop();
		setProp(s2, "2", summ(profitShop2));

		std::map<Month, double> profitShop3 = {
			{ Month::September, 2200 },
			{ Month::October,   3525 },
			{ Month::November,  1200 }
		};

		Shop* s3 = new Shop();
		setProp(s3, "3", summ(profitShop3));

		s2->serialize();

		// this signature is better than deserialization would be called on an instance of the class
		auto s2_2 = Shop::deserialize();

		std::vector<Shop*> shops = { &s1, s2, s3 };

		std::sort(shops.begin(), shops.end(), [](Shop* s1, Shop* s2) {
			return s1->get_sumProfit() > s2->get_sumProfit(); 
		});

		for (auto item : shops)
		{
			std::cout << "Name: " << item->get_name() 
				<< " Profit: " << item->get_sumProfit() << std::endl;
		}

		std::cout << std::endl;

		int numberOfMonths = 3;

		std::sort(shops.begin(), shops.end(), [numberOfMonths](Shop* s1, Shop* s2) { 
			return s1->get_sumProfit() / numberOfMonths > s2->get_sumProfit() / numberOfMonths;
		});

		for (auto item : shops)
		{
			std::cout << "Name: " << item->get_name()
				<< " Average profit: " << item->get_sumProfit() / numberOfMonths << std::endl;
		}

		delete s2;
		delete s3;
	}

	return 0;
}
