#pragma once
#include <vector>
#include <algorithm>
#include "Card.h"

class Deck
{
public:
	Deck();
	~Deck();

	int GetCount();
	Card*& GetCard();

	void FillDeck();
	void Clear—ards();
	void Shuffle();

private:
	std::vector<Card*> cards;
};

