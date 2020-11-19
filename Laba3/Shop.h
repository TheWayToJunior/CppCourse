#pragma once
#include <string>

#define PROPERTIES(type, var)  protected: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class Shop
{
public:
	Shop(std::string name, std::string address, double totalProfit);

	enum WorkMod
	{
		Default,
		AroundClock
	};

	double get_Income();

	PROPERTIES(int, Id);
	PROPERTIES(std::string, Name);
	PROPERTIES(std::string, Address);
	PROPERTIES(std::string, YearOfFoundation);
	PROPERTIES(WorkMod, Works);
	PROPERTIES(double, TotalProfit);
	PROPERTIES(int, NumberCustomersDiscount);

protected:
	double income;
};

