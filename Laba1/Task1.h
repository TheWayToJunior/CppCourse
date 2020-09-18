#pragma once

#include <iostream>

/* ������� 1

�������� ������ �� n=20 ������������ �����, ������������������� ������. �������
processArray() ������ ��������� ������ ���������� ������� �� -20.0 �� 70.0, �
����� ������������� ������, �.�. �������� ������ ������� ������� �� ������������
�� ������ �������� � �������. ��� �������� ��� ����� ������ ������� �� ������.
������������ �������� ������������ ������, � ������� ��� ��������, ������� ��
������� ������������� �������� ������������, ��������� �������� ��������
�������, � ��������� ����� x (����� x ������ � ����������). ������� �� �����
�������������� �������.

������:
����: [ 18 49 68 -13 15 -13 65 45 -10 -8 -17 0 42 -9 -3 61 15 -15 7 -10 ] x = 2.7

�����: max Item = 68
	[ 0.264706 0.720588 1 -0.191176 0.220588 -0.191176 0.955882 0.661765
	 -0.147059 -0.117647 -0.25 0 0.617647 -0.132353 -0.0441176 0.897059 0.220588
	 -0.220588 0.102941 -0.147059 ]

	[ 0.264706 0.720588 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 2.7 ]
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