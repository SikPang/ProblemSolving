#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "QuickSort.hpp"

static void sortChecker(std::vector<int>& buf)
{
	for (int i=0; i<(int)buf.size()-1; ++i)
	{
		if (buf[i] > buf[i+1])
		{
			std::cout << "\e[31mX\e[0m ";
			return;
		}
	}
	std::cout << "\e[32mV\e[0m ";
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "<Usage> : ./a.out 5 2 4 1 3\n";
		return 1;
	}

	std::vector<int> buf;
	buf.reserve(ac);

	for (int i=1; i<ac; ++i)
		buf.push_back(atoi(av[i]));

	quick::sort(buf);
	
	sortChecker(buf);
	return 0;
}