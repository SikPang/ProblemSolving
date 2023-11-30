#include "HeapSort.hpp"

namespace heap
{

// 최대 힙
void sort(std::vector<int>& buf)
{
	// 이미 돼있다.

	/*
					0
			1				2
		3		4		5		6
	7	8	9
	
	2x+1, 2x+2

	(x-1)/2
	
	0, 1, 2
	1, 3, 4
	2, 5, 6
	3, 7, 8
	4,  9, 10
	*/

	
}

}

#include <vector>
#include <iostream>
int main()
{
	std::vector<int> buf = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	heap::sort(buf);
	for (int i=0; i<buf.size(); ++i)
		std::cout << buf[i] << " ";
	std::cout << "\n";
}