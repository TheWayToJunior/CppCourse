#include <iostream>
#include <cstring>

class Task3 
{
public:
	void run()
	{
		const char* string1 = "Hello";
		const char* string2 = "World";

		std::cout << "string1 = " << string1 << std::endl;
		std::cout << "string2 = " << string2 << std::endl;
		std::cout << "\nmy result = " << strcmp(string1, string2) << std::endl;
		std::cout << "strcmp result = " << std::strcmp(string1, string2) << std::endl;
	}

private:
	int strcmp(const char* string1, const char* string2)
	{
		unsigned f = strnum(string1);
		unsigned l = strnum(string2);

		if (f == l) 
			return 0;

		return f < l ? -1 : 1;
	}

	int strlen(const char* string)
	{
		int res = 0;

		while (*string++)
			++res;

		return res;
	}

	int strnum(const char* string)
	{
		int num = 0;

		while (*string)
		{
			num += *string++;
		}

		return num;
	}
};