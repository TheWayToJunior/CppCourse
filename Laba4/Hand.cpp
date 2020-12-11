#include "Hand.h"

Hand::~Hand()
{
	ClearĐards();
}

void Hand::AddCard(Card* card)
{
	this->cards.push_back(card);
}

void Hand::ClearĐards()
{
	if(!cards.empty())
		cards.erase(cards.begin(), cards.end());
}

const std::vector<Card*>& Hand::GetCards()
{
	return this->cards;
}

int Hand::GetTotal() const
{
	int result = 0;

	for (auto card : this->cards)
	{
		result += card->GetValue();
	}

	return result;
}
