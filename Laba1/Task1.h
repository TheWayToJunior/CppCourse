#pragma once

#include <iostream>
#include "SharedArrayr.h"

class Task1 
{
public:
	void run()
	{
		print<float>(processArray(2.5));
	}

private:
	template<typename T>
	void print(SharedArray<T> sptr)
	{
		for (size_t i = 0; i < sptr.getSize(); i++)
		{
			std::cout << "mass[" << i << "] = " << sptr[i] << std::endl;
		}
	}

	SharedArray<float> processArray(float valueX)
	{
		int arrSize = 20;

		SharedArray<int> arrSptr(arrSize);

		arrSptr.generateValueArray(-20, 70);

		ItemSharedArray<int> max = arrSptr.getMaxObject();

		print<int>(arrSptr);

		std::cout << "\nmax: " << max.value << " position: " << max.pisition << "\n\n";

		SharedArray<float> arrSptrF(arrSize);

		for (int i = 0; i < arrSptrF.getSize(); i++)
		{
			if (max.pisition <= i)
				arrSptrF[i] = valueX;
			else
				arrSptrF[i] = (float)arrSptr[i] / max.value;
		}

		return arrSptrF;
	}
};