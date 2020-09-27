#pragma once

#include <string>

#define PROPERTIES(type, var)  private: type var; \
	public: type get_##var() const { return var; } \
            void set_##var(type val) { var = val; }

class Shop
{
public:
	Shop() = default;
	Shop(
		std::string name,
		std::string address,
		std::string date,
		int number,
		int sumProfit);

	PROPERTIES(std::string, name);
	PROPERTIES(std::string, address);
	PROPERTIES(std::string, date);
	PROPERTIES(int, number);
	PROPERTIES(int, sumProfit);
};

