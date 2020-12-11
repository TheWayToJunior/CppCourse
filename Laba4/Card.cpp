#include "Card.h"

Card::Card(Card::Rank rank, Card::Suit suit, bool isFaceUp)
	: rank(rank), suit(suit), isFaceUp(isFaceUp)
{
}

Card::Rank Card::GetRank() const
{
	return this->rank;
}

Card::Suit Card::GetSuit() const
{
	return this->suit;
}

int Card::GetValue() const
{
	if (this->rank > 10)
	{
		return 10;
	}

	return static_cast<int>(this->rank);
}

std::string Card::ToString()
{
	const std::string ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8",
		"9", "10", "J", "D", "K" };

	int suit[] = { 3, 4, 5, 6 };

	return ranks[this->rank - 1] + (char)suit[this->suit];
}

void Card::Flip()
{
	this->isFaceUp = !isFaceUp;
}

std::ostream& operator<<(std::ostream& os, Card& card)
{
	if (card.isFaceUp)
	{
		os << card.ToString();
	}
	else
	{
		os << "??";
	}

	return os;
}
