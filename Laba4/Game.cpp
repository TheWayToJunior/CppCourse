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
		throw std::exception("������������ �������!");

	this->deck->FillDeck();

	DeckFormattable format;
	std::string command = "";

	deck->Shuffle();

	do
	{
		player->GetHand()->AddCard(deck->GetCard());
		PrettyPrint(format);

		std::cout << "����������? "; std::cin >> command; std::cout << std::endl;

	} while (command != "-");

	dealer->Move(deck);
	PrettyPrint(format);

	bool playerIsWinner = this->IsWinner(this->player->GetHand(), this->dealer->GetHand());

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
	this->player->GetHand()->Clear�ards();
	this->dealer->GetHand()->Clear�ards();

	this->deck->Clear�ards();
}

void Game::PrettyPrint(IFormattable& formattable)
{
	std::cout << "������: "  << "[" << deck->GetCount()                << "]" << std::endl;

	std::string str = formattable.Format(dealer->GetHand()->GetCards());
	std::wstring wstr(str.begin(), str.end());
	
	std::cout << "������:  ";
	std::wcout << wstr << " : " << dealer->GetHand()->GetTotal() << std::endl;

	std::cout << "��:      " << formattable.Format(player->GetHand()->GetCards()) << " : " << player->GetHand()->GetTotal() << std::endl;
}