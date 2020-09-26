#pragma once
#include <sstream>
#include <ostream>
#include <iostream>
#include <string.h>

class Fraction
{
public:
	Fraction(int x, int y);
	~Fraction();

	int getX();
	int getY();
	void reduce();

	static int getCount();
	static int gcd(int n, int m);
	static void printAsFraction(double decimal_fraction);
	static void printAsFraction(char* decimal_fraction);

	Fraction operator+(const Fraction& f);
	Fraction operator-(const Fraction& f);
	Fraction operator*(const Fraction& f);
	Fraction operator/(const Fraction& f);

	friend std::ostream& operator<<(std::ostream& os, const Fraction& obj);

private:
	int x;
	int y;

	static int count;
};

