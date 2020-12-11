#pragma once
#include <string>
#include <vector>
#include "Card.h"

class IFormattable
{
public:
	virtual ~IFormattable() {};
	virtual std::string Format(const std::vector<Card*>& cards) = 0;
};