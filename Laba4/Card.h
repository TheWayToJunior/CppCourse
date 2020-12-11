#pragma once
#include <ostream>
#include <windows.h>

class Card
{
public:
	enum Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
	enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

	Card(Rank rank, Suit suit, bool isFaceUp = true);

	Card::Rank GetRank() const;
	Card::Suit GetSuit() const;
	int GetValue() const;

	std::string ToString();

	void Flip();

	friend std::ostream& operator<<(std::ostream& os, Card& aCard);

private:
	Card::Rank rank;
	Card::Suit suit;
	bool isFaceUp;
};

