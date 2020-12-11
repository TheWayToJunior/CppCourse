#pragma once
#include <iostream>
#include "Deck.h"
#include "Dealer.h"
#include "Player.h"
#include "IFormattable.h"
#include "DeckFormattable.h"

class Game
{
public:
	Game(Player* player);
	~Game();

	void Play(const float& bet);
	void Dispose();

private:
	Deck* deck;
	Dealer* dealer;
	Player* player;

	void PrettyPrint(IFormattable& format);

	// ToDo: Create the class rules of the game
	/// <summary>
	/// Ñhecks the winning situation
	/// </summary>
	/// <param name="player"></param>
	/// <param name="dealer">Object that is being checked against</param>
	/// <returns>If the argument wins, player returns true, otherwise false</returns>
	bool IsWinner(const Hand* player, const Hand* dealer);
	bool ExcessScore(const Hand* hand);
};

