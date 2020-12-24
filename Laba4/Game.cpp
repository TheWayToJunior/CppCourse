#include "Game.h"
#include <locale>

Game::Game(Player* player)
{
	this->player = player;

	this->dealer = new Dealer();
	this->deck = new Deck();
}

Game::~Game()
{
	delete this->dealer;
	delete this->deck;
}

void Game::Play(const float& bet)
{
	if (player->GetBalance() < bet)
		throw std::exception("Недостаточно средств!");

	this->deck->FillDeck();

	DeckFormattable format;
	std::string command = "";

	deck->Shuffle();

	do
	{
		player->GetHand()->AddCard(deck->GetCard());
		PrettyPrint(format);

		std::cout << "Продолжить? "; std::cin >> command; std::cout << std::endl;

	} while (command != "-");

	dealer->Move(deck);
	PrettyPrint(format);

	bool playerIsWinner = this->IsWinner(this->player->GetHand(), this->dealer->GetHand());

	if (playerIsWinner)
	{
		std::cout << "Вы выиграли!"<< std::endl;
		this->player->Award(bet * 2);
	}
	else
	{
		std::cout << "Вы проиграли!" << std::endl;
		this->player->Collect(bet);
	}

	std::cout << "Баланс: " << player->GetBalance() << std::endl << std::endl;
}

bool Game::IsWinner(const Hand* playerHand, const Hand* dealerHand)
{
	if (this->ExcessScore(playerHand))
		return false;

	if (this->ExcessScore(dealerHand))
		return true;

	return playerHand->GetTotal() > dealerHand->GetTotal();
}

bool Game::ExcessScore(const Hand* hand)
{
	return hand->GetTotal() > 21;
}

void Game::Dispose()
{
	this->player->GetHand()->ClearСards();
	this->dealer->GetHand()->ClearСards();

	this->deck->ClearСards();
}

void Game::PrettyPrint(IFormattable& formattable)
{
	std::cout << "Колода: "  << "[" << deck->GetCount()                << "]" << std::endl;

	std::string str = formattable.Format(dealer->GetHand()->GetCards());
	std::wstring wstr(str.begin(), str.end());
	
	std::cout << "Диллер:  ";
	std::wcout << wstr << " : " << dealer->GetHand()->GetTotal() << std::endl;

	std::cout << "Вы:      " << formattable.Format(player->GetHand()->GetCards()) << " : " << player->GetHand()->GetTotal() << std::endl;
}