#include "Deck.h"
#include <time.h>

Deck::Deck()
{
	this->cards.reserve(52);
}

Deck::~Deck()
{
	ClearСards();
}

int Deck::GetCount()
{
	return cards.size();
}

void Deck::ClearСards()
{
	if (!cards.empty())
	{
		for (auto card : cards)
		{
			delete card;
		}

		cards.clear();
	}
}

void Deck::Shuffle()
{
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(cards.begin(), cards.end());
}

Card*& Deck::GetCard()
{
	if (cards.empty())
	{
		throw std::exception("Deck is empty");
	}

	auto card = cards.back();
	cards.pop_back();

	return card;
}

void Deck::FillDeck()
{
	for (int s = Card::HEARTS; s <= Card::SPADES; ++s)
	{
		for (int r = Card::ACE; r <= Card::KING; ++r)
		{
			cards.push_back(new Card(static_cast<Card::Rank>(r), static_cast<Card::Suit>(s)));
		}
	}
}
