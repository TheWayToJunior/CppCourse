#pragma once
#include <string>


class Book
{
public:
	std::string name;
	std::string author;
	int year;

	Book(std::string name, std::string author, int year)
	{
		name = name;
		author = author;
		year = year;
	}
	std::string getAuthor()
	{
		return author;
	}
	std::string getName()
	{
		return name;
	}
};