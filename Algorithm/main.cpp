#include <vector>
#include <algorithm>

#include <iostream>
#include <cstdlib>

void sortChecker(std::vector<int>& buf)
{
	for (int i=0; i<buf.size()-1; ++i)
	{
		if (buf[i] > buf[i+1])
		{
			std::cout << "* Failure\n";
			return;
		}
	}
	std::cout << "* Success\n";
}

void printBuf(std::vector<int>& buf, const char* msg)
{
	if (msg)
		std::cout << msg << ": ";
	for (int i=0; i<buf.size(); ++i)
		std::cout << buf[i] << " ";
	std::cout << "\n";
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cout << "<Usage> : ./a.out 5 2 4 1 3\n";
		return 1;
	}
	std::vector<int> buf;

	for (int i=1; i<ac; ++i)
		buf.push_back(atoi(av[i]));
	
	printBuf(buf, "before");

	// sort

	printBuf(buf, "after");
	sortChecker(buf);
	return 0;
}