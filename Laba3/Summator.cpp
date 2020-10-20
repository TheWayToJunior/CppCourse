#include "Summator.h"

Summator::Summator()
    : ExpressionEvaluator::ExpressionEvaluator()
{
}

Summator::Summator(size_t n) 
    : ExpressionEvaluator::ExpressionEvaluator(n)
{
}

void Summator::logToScreen()
{
    std::cout << this->joinOperands(" + ") << " = " << this->calculate() << "\n";
}

void Summator::logToFile(const std::string& fileName)
{
    std::string str = this->joinOperands(" + ");

    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);
    ofs << str +  " = " + std::to_string(this->calculate()) + "\n";
    ofs.close();
}

double Summator::calculate()
{
	double result = NULL;

	for (size_t i = 0; i < this->countOperands; i++)
	{
		result += this->operands[i];
	}

	return result;
}