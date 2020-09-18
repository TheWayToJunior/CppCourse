#pragma once

#include <iostream>
#include "SharedArrayr.h"

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