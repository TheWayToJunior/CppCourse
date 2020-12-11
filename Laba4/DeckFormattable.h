#pragma once
#include "IFormattable.h"
#include "Card.h"
#include <vector>


class DeckFormattable : public IFormattable
{
public:
	std::string Format(const std::vector<Card*>& cards) override;

private:
	std::vector<Card*> cards;
};

