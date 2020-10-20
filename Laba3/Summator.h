#pragma once
#include "ExpressionEvaluator.h"

class Summator : public ExpressionEvaluator
{
public:
	Summator();
	Summator(size_t n);

	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	double calculate() override;
};

