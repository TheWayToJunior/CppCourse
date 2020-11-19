#include "Boutique.h"

Boutique::Boutique(std::string name, std::string address, double totalProfit)
	: Shop(name, address, totalProfit)
{
}

void Boutique::payTax()
{
	this->income = this->TotalProfit - static_cast<double>(2000 + 65 * 122);
}
