#include "Dealer.h"

void Dealer::Move(Deck* deck)
{
	int count = std::rand() % 5 + 2;

	for (size_t i = 0; i < count; i++)
	{
		if (this->GetHand()->GetTotal() > 21)
			break;

		this->GetHand()->AddCard(deck->GetCard());
	}
}
