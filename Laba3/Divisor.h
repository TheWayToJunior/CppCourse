#pragma once
#include "ExpressionEvaluator.h"

class Divisor : public ExpressionEvaluator
{
public:
	Divisor();
	Divisor(size_t n);

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	double calculate() override;
};

