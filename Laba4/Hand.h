#pragma once
#include <vector>
#include "Card.h"

class Hand
{
public:
	virtual ~Hand();

	void AddCard(Card* card);
	void Clear—ards();

	const std::vector<Card*>& GetCards();
	int GetTotal() const;

private:
	std::vector<Card*> cards;
};

