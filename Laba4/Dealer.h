#pragma once
#include "PlayerBase.h"
#include "Deck.h"

class Dealer : public PlayerBase
{
public:
	/// <summary>
	/// Dealer game logic
	/// </summary>
	/// <param name="deck"></param>
	void Move(Deck* deck);
};

