#include "Fraction.h"

Fraction::Fraction(int x, int y)
{
	this->x = x;
	this->y = y;

	count++;
}

Fraction::~Fraction()
{
	count--;
}

int Fraction::getX()
{
	return this->x;
}

int Fraction::getY()
{
	return this->y;
}

int Fraction::count = 0;

int Fraction::getCount()
{
	return Fraction::count;
}

void Fraction::reduce()
{
	int commonDivisor = Fraction::gcd(this->x, this->y);
	this->x /= commonDivisor;
	this->y /= commonDivisor;
}

int Fraction::gcd(int n, int m)
{
	return (n == 0) ? m : gcd(m % n, n);
}

void Fraction::printAsFraction(double decimal_fraction)
{
	// Конвертим double в char*
	std::stringstream ss;
	ss << decimal_fraction;
	char* str = _strdup(ss.str().c_str());

	// Получаем дробную и целую часть
	char* next_token = NULL;
	char* token = strtok_s(str, ".", &next_token);

	// ...
	int lenght = strnlen_s(next_token, sizeof next_token);

	int y = pow(10, lenght);

	Fraction f(decimal_fraction * y, y);
	f.reduce();

	std::cout << f.getX() << "/" << f.getY() << std::endl;

}

void Fraction::printAsFraction(char* decimal_fraction)
{
	// Разбиваем строку на две части: 
	// token - первая;
	// next_token - вторая.
	// =)

	char* next_token = NULL;
	char* token = strtok_s(decimal_fraction, "/", &next_token);

	if(next_token != nullptr && *next_token != NULL)
		std::cout << (float)atoi(token) / (float)atoi(next_token) << std::endl; // Конвертим токены в int(atoi) и делим
	else
		std::cout << "Invalid formatter: " << decimal_fraction << std::endl;
}

Fraction Fraction::operator+(const Fraction& f)
{
	int x = this->x * f.y + f.x * this->y;
	int y = this->y * f.y;

	return Fraction(x, y);
}

Fraction Fraction::operator-(const Fraction& f)
{
	int x = this->x * f.y - f.x * this->y;
	int y = this->y * f.y;

	return Fraction(x, y);
}

Fraction Fraction::operator*(const Fraction& f)
{
	return Fraction(this->x * f.x, this->y * f.y);
}

Fraction Fraction::operator/(const Fraction& f)
{
	return Fraction(this->x * f.y, this->y * f.x);
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	os << (float)obj.x / (float)obj.y;

	return os;
}
