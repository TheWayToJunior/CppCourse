#pragma once
#include <vector>

class ArraySorter
{
public:
	template<class TItem, class Pred>
	static void bubbleSorting(std::vector<TItem>& arr, Pred pred)
	{
		for (int i = 1; i < arr.size(); i++)
		{
			for (int j = 0; j < arr.size() - i; j++)
			{
				if (pred(arr[j], arr[j + 1]))
				{
					auto temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
};

