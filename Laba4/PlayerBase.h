#pragma once
#include "Hand.h"

class PlayerBase
{
public:
	PlayerBase()
	{
		hand = new Hand();
	}

	~PlayerBase()
	{
		delete hand;
	}

	Hand* GetHand()
	{
		return hand;
	}

private:
	Hand* hand;
};