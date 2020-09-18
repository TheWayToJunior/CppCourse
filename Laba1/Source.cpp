#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"


int main()
{
	std::cout << "Task1: " << std::endl;

	Task1 t1;
	t1.run();

	std::cout << "\nTask2: " << std::endl;

	Task2 t2;
	t2.run();

	std::cout << "\nTask3: " << std::endl;

	Task3 t3;
	t3.run();
}
