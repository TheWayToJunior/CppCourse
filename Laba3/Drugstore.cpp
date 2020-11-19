#include "Drugstore.h"


Drugstore::Drugstore(std::string name, std::string address, double totalProfit)
	: Shop(name, address, totalProfit)
{
}

void Drugstore::payTax()
{
	this->income = this->TotalProfit - 2000;
}
