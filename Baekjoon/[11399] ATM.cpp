#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec;
	int answer = 0;
	int time = 0;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i)
	{
		answer += vec[i] + time;
		time += vec[i];
	}

	cout << answer;
}