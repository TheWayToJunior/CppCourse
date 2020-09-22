#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> vector (10);

	std::cout << vector.getSize() << std::endl << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		vector[i] = i;
	}

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << vector[i] << "  ";
	}

	auto old = vector--;

	std::cout << std::endl << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << old[i] << "  ";
	}

	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		std::cout << vector[i] << "  ";
	}
}
