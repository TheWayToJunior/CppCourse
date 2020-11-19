#pragma once

#include <iostream>
#include <cstring>
#include <fstream>
#include "ILoggable.h"

class ExpressionEvaluator : public ILoggable 
{
public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual ~ExpressionEvaluator();

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	virtual double calculate() = 0;

	void setOperand(int pos, double value);
	void setOperands(double ops[], size_t n);

protected:
	size_t countOperands;
	double* operands;

	std::string joinOperands(std::string str);
};