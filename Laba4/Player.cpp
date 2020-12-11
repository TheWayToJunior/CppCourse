#include "Player.h"

Player::Player(const std::string& name, const float& balance)
	: name(name), balance(balance)
{
}

void Player::Collect(const float& bet)
{
	this->balance -= bet;
}

void Player::Award(const float& value)
{
	this->balance += value;
}

float Player::GetBalance()
{
	return this->balance;
}
