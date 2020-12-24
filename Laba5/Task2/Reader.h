#pragma once
#include <string>
#include <fstream>
#include<map>
#include <algorithm>

class Reader 
{
public:
	std::map<std::string, int> reade()
	{
        bool flag = true;

        std::map< std::string, int > mass;
        std::string line;
        std::ifstream in("data.txt");

        if (in.is_open())
        {
            while (getline(in, line))
            {
                const size_t MAXLEN = 1000;
                char text[MAXLEN];
                in.getline(text, MAXLEN);

                char* substr = strtok_s(text, ".,:!;? ", NULL);

                while (substr != 0)
                {
                    std::string word = substr;

                    std::transform(word.begin(), word.end(), word.begin(), std::tolower);

                    if (word.size() > 3)
                    {
                        for (auto mass_it = mass.begin(); mass_it != mass.end(); ++mass_it)
                        {
                            if (mass_it->first == word)
                            {
                                mass_it->second = mass_it->second++;
                                flag = false;
                            }
                        }
                    }

                    if (flag == true)
                    {
                        mass.insert(std::make_pair(word, 1));
                    }

                    flag = true;
                    substr = strtok_s(NULL, ".,:!;? ", NULL);
                }
            }
        }
        in.close();

        return mass;
	}
};