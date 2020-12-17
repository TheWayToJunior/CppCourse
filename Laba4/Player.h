#pragma once
#include "string"
#include "PlayerBase.h"

class Player : public PlayerBase
{
public:
	Player(const std::string& name, const float& balance);

	void Collect(const float& bet);
	void Award(const float& value);

	float GetBalance();

private:
	std::string name;
	float balance;
};

