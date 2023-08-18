#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int get1FromBinary(int num)
{
	int result = 0;
	
	while (num != 0)
	{
		if (num % 2 == 1)
			++result;
		num /= 2;
	}
	return result;
}

int main() {
	int num, target;
	cin >> num >> target;
	
	vector<pair<int, int>> vec;
	vec.reserve(num);
	
	for (int i = 0; i < num; ++i)
	{
		int input;
		cin >> input;
		
		vec.push_back(make_pair(input, get1FromBinary(input)));
	}
	
	sort(vec.begin(), vec.end(), compare);
	
	cout << vec[target - 1].first << "\n";
	
	return 0;
}