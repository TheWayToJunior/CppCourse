#include <iostream>
#include "Summator.h"
#include "Divisor.h"
#include "CustomEE.h"
#include "Drugstore.h"
#include "Boutique.h"
#include "ITaxPayments.h"


void Log(ILoggable& s)
{
	s.logToScreen();
	s.logToFile("log.txt");
}

int main()
{
	double mass[]{ 0, 1, -4, -3, 2 };

	Summator s;
	s.setOperands(mass, 5);

	Log(s);

	Divisor d(2);
	d.setOperand(0, 10);
	d.setOperand(1, 2);

	Log(d);

	CustomEE c;
	c.setOperands(mass, 5);
	c.shuffle();

	Log(c);

	ITaxPayments* drugstore = new Drugstore("", "", 20000);
	drugstore->payTax();

	ITaxPayments* boutique = new Boutique("", "", 72500);
	boutique->payTax();

	delete drugstore;
	delete boutique;
}
