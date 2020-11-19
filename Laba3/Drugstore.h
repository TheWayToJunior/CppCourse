#pragma once
#include "Shop.h"
#include "ITaxPayments.h"

class Drugstore : public Shop, public ITaxPayments
{
public:
	Drugstore(std::string name, std::string address, double totalProfit);

	void payTax() override;
};

