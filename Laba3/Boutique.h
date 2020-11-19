#pragma once
#include "Shop.h"
#include "ITaxPayments.h"

class Boutique : public Shop, public ITaxPayments
{
public:
	Boutique(std::string name, std::string address, double totalProfit);

	void payTax() override;
};

