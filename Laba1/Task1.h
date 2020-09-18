#pragma once

#include <iostream>

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

class Task1 
{
public:
	void run()
	{
		const int size = 20;
		int mass[size];

		float* massF = processArray(mass, 2.5);

		print<float>(massF, size);

		delete[] massF;
	}

private:
	template<typename T>
	void print(T* sptr, int size)
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << "mass[" << i << "] = " << sptr[i] << std::endl;
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

		print<int>(mass, size);

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

		std::cout << "\nmax: "<< maxItem << "  position: " << positionMaxItem << "\n\n";

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
};
