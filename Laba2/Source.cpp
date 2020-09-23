#include <iostream>
#include "Vector.cpp"
#include "Matrix.cpp"

int main()
{
    Vector<int> vector (10);
	
	Matrix<int> matrix (5, 5);

	for (size_t i = 0; i < matrix.getRows(); i++)
	{
		for (size_t j = 0; j < matrix.getCells(); j++)
		{
			matrix[i][j] = 1;
		}
	}

	for (size_t i = 0; i < matrix.getRows(); i++)
	{
		for (size_t j = 0; j < matrix.getCells(); j++)
		{
			std::cout << matrix[i][j] << "  ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
	auto m2 = matrix--;

	for (size_t i = 0; i < matrix.getRows(); i++)
	{
		for (size_t j = 0; j < matrix.getCells(); j++)
		{
			std::cout << matrix[i][j] << "  ";
		}

		std::cout << std::endl;
	}

	std::cout << std::endl << vector.getSize() << std::endl << std::endl;

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
