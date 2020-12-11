#include "Game.h"

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
		throw std::exception("������������ �������!");

	this->deck->FillDeck();

	DeckFormattable format;
	std::string command = "";

	deck->Shuffle();

	do
	{
		player->AddCard(deck->GetCard());
		PrettyPrint(format);

		std::cout << "����������? "; std::cin >> command; std::cout << std::endl;

	} while (command != "-");

	dealer->Move(deck);
	PrettyPrint(format);

	bool playerIsWinner = this->IsWinner(this->player, this->dealer);

	if (playerIsWinner)
	{
		std::cout << "�� ��������!"<< std::endl;
		this->player->Award(bet * 2);
	}
	else
	{
		std::cout << "�� ���������!" << std::endl;
		this->player->Collect(bet);
	}

	std::cout << "������: " << player->GetBalance() << std::endl << std::endl;
}

bool Game::IsWinner(const Hand* player, const Hand* dealer)
{
	if (this->ExcessScore(player))
		return false;

	if (this->ExcessScore(dealer))
		return true;

	return player->GetTotal() > dealer->GetTotal();
}

bool Game::ExcessScore(const Hand* hand)
{
	return hand->GetTotal() > 21;
}

void Game::Dispose()
{
	this->player->Clear�ards();
	this->dealer->Clear�ards();

	this->deck->Clear�ards();
}

void Game::PrettyPrint(IFormattable& formattable)
{
	std::cout << "������: "  << "[" << deck->GetCount()                << "]" << std::endl;
	std::cout << "������:  " << formattable.Format(dealer->GetCards()) << " : " << dealer->GetTotal() << std::endl;
	std::cout << "��:      " << formattable.Format(player->GetCards()) << " : " << player->GetTotal() << std::endl;
}