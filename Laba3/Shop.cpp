#include "Shop.h"

Shop::Shop(std::string name, std::string address, double totalProfit)
{
	this->Name = name;
	this->Address = address;
	this->TotalProfit = totalProfit;
}

double Shop::get_Income()
{
	return this->income;
}
