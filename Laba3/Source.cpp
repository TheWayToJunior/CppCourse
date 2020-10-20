#include <iostream>
#include "Summator.h"
#include "Divisor.h"

int main()
{
	double mass[]{ 0, 1, 2, -3, 4 };

	Summator s;
	s.setOperands(mass, 5);

	s.logToScreen();
	s.logToFile("log.txt");

	Divisor d(2);
	d.setOperand(0, 10);
	d.setOperand(1, 2);

	d.logToScreen();
	d.logToFile("log.txt");
}
