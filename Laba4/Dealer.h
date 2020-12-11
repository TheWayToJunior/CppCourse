#pragma once
#include "Hand.h"
#include "Deck.h"

class Dealer : public Hand
{
public:
	/// <summary>
	/// Dealer game logic
	/// </summary>
	/// <param name="deck"></param>
	void Move(Deck* deck);
};

