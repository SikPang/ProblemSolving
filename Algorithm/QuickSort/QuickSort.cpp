#include "QuickSort.hpp"

namespace quick
{
	static void swap(int& first, int& second)
	{
		int temp = first;
		first = second;
		second = temp;
	}

	static void recursion(std::vector<int>& buf, int start, int end)
	{
		if (start >= end)
			return;

		int& pivot = buf[start];
		int left = start + 1;
		int right = end;

		while (true)
		{
			while (left <= right && buf[left] <= pivot)
				++left;
			while (left <= right && buf[right] > pivot)
				--right;
				
			if (left > right)
				break;
			swap(buf[left], buf[right]);
		}

		quick::swap(pivot, buf[right]);
		recursion(buf, start, right - 1);
		recursion(buf, right + 1, end);
	}

	void sort(std::vector<int>& buf)
	{
		recursion(buf, 0, buf.size()-1);
	}
}