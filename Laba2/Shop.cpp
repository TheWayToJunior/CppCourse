#include "Shop.h"

Shop::Shop(std::string name, std::string address, std::string date, int number, int sumProfit)
	:name(name), address(address), date(date), number(number), sumProfit(sumProfit)
{
}

void Shop::serialize(const std::string& filename)
{
	Serializer<Shop> sterilizer(filename);
	sterilizer.sterilize(*this);
}

void Shop::serialize()
{
	this->serialize("mytext.txt");
}

Shop Shop::deserialize(const std::string& filename)
{
	Serializer<Shop> sterilizer(filename);
	return sterilizer.deserialize();
}

Shop Shop::deserialize()
{
	return Shop::deserialize("mytext.txt");
}
