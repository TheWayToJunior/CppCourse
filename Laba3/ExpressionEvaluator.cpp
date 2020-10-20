#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() 
    : ExpressionEvaluator::ExpressionEvaluator(20)
{
}

ExpressionEvaluator::ExpressionEvaluator(size_t n)
{
    this->countOperands = n;
    this->operands = new double[this->countOperands];
    memset(this->operands, 0,   this->countOperands);
}

ExpressionEvaluator::~ExpressionEvaluator()
{
    delete[] this->operands;
}

void ExpressionEvaluator::logToScreen()
{
    for (size_t i = 0; i < this->countOperands; i++)
    {
        std::cout << this->operands[i] << "; ";
    }
}

void ExpressionEvaluator::logToFile(const std::string& fileName)
{
    std::string str;

    for (size_t i = 0; i < this->countOperands; i++)
    {
        str += this->operands[i];
        str += "; ";
    }

    std::ofstream ofs(fileName, std::ofstream::out);
    ofs << str;
    ofs.close();
}

void ExpressionEvaluator::setOperand(int pos, double value)
{
    if (pos < 0 || pos >= this->countOperands)
    {
        throw std::exception("Argument out of range");
    }

    this->operands[pos] = value;
}

void ExpressionEvaluator::setOperands(double ops[], size_t n)
{
    if (this->operands)
    {
        delete[] this->operands;
    }

    this->operands = new double[n];
    std::memcpy(this->operands, ops, sizeof(double) * n);

    this->countOperands = n;
}

std::string ExpressionEvaluator::joinOperands(std::string s)
{
    std::string str;

    for (size_t i = 0; i < this->countOperands; i++)
    {
        str += this->operands[i] >= 0 ? std::to_string(this->operands[i])
            : "(" + std::to_string(this->operands[i]) + ")";

        if (i != this->countOperands - 1)
            str += s;
    }

    return str;
}
