#include "MergeSort.hpp"
#include <iostream>

namespace merge
{
static void merge(std::vector<int>& buf, std::vector<int>& result, int start, int middle, int end)
{
	int left = start;
	int right = middle + 1;

	for (int i=start; i<=end; ++i)
	{
		if (right > end || (left <= middle && buf[left] <= buf[right]))
			result[i] = buf[left++];
		else if (left > middle || (right <= end && buf[left] > buf[right]))
			result[i] = buf[right++];
	}
}

static void recursion(std::vector<int>& buf, std::vector<int>& result, int start, int end)
{
	if (start >= end)
		return;

	int middle = (start + end)/2;

	recursion(buf, result, start, middle);
	recursion(buf, result, middle+1, end);

	merge(buf, result, start, middle, end);

	for (int i=start; i<=end; ++i)
		buf[i] = result[i];
}

void sort(std::vector<int>& buf)
{
	std::vector<int> result(buf.size());
	recursion(buf, result, 0, buf.size()-1);
}
}