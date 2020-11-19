#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <algorithm>

class CustomEE : public ExpressionEvaluator, public IShuffle
{
public:
	void logToScreen() override;
	void logToFile(const std::string& fileName) override;

	void shuffle() override;
	void shuffle(size_t i, size_t j) override;

	double calculate() override;
};

