#include "Divisor.h"

Divisor::Divisor() 
    : ExpressionEvaluator::ExpressionEvaluator()
{
}

Divisor::Divisor(size_t n)
    : ExpressionEvaluator::ExpressionEvaluator(n)
{
}

void Divisor::logToScreen()
{
    std::cout << this->joinOperands(" / ") << " = " << this->calculate() << "\n";
}

void Divisor::logToFile(const std::string& fileName)
{
    std::string str = this->joinOperands(" / ");

    std::ofstream ofs(fileName, std::ofstream::out | std::ofstream::app);
    ofs << str + " = " + std::to_string(this->calculate()) + "\n";
    ofs.close();
}

double Divisor::calculate()
{
    double result = 1;

    for (size_t i = 0; i < this->countOperands; i++)
    {
        if (this->operands[i] == 0)
        {
            return NULL;
        }

        result /= this->operands[i];
    }

    return result;
}
