#include "CustomEE.h"

void CustomEE::logToScreen()
{
	std::string str = "";

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
			: "(" + std::to_string(this->operands[i]) + ")";

		if (i != this->countOperands - 1)
			str += i % 2 == 0 && i != 1 ? " + " : " - ";
	}

	std::cout << str << " = " << this->calculate() << "\n";
}

void CustomEE::logToFile(const std::string& fileName)
{
	std::string str = "";
	std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);

	for (size_t i = 0; i < this->countOperands; i++)
	{
		str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
			: "(" + std::to_string(this->operands[i]) + ")";

		if (i != this->countOperands - 1)
			str += i % 2 == 0 && i != 1 ? " + " : " - ";
	}

	ofs << str << " = " << this->calculate() << "\n";
	ofs.close();
}

template<class TItem, class Pred>
static void bubbleSorting(TItem*& arr, size_t size,  Pred pred)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (pred(arr[j], arr[j + 1]))
			{
				auto temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void CustomEE::shuffle()
{
	bubbleSorting(this->operands, this->countOperands, [](double l, double r) { return r < l; });
}

void CustomEE::shuffle(size_t i, size_t j)
{
	if (this->operands[i] < 0 && this->operands[j] >= 0)
	{
		auto temp = this->operands[j];
		this->operands[j] = this->operands[i];
		this->operands[i] = temp;
	}
}

double CustomEE::calculate()
{
    double result = 1;

	for (size_t i = 0; i < this->countOperands; i++)
	{
		if (i % 2 == 0 && i != 1)
		{
			result += this->operands[i];
		}
		else
		{
			result -= this->operands[i];
		}
	}

    return result;
}
