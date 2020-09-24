#pragma once

class Fraction
{
public:
	Fraction(int x, int y);

	Fraction operator + (const Fraction& f);
	Fraction operator-(const Fraction& f);

private:
	int x;
	int y;
};

