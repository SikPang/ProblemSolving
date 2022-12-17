#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec;
	int cnt = 0;
	int sum = 0;

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}

	for (int i = n - 1; i >= 0; --i)
	{
		while (vec[i] + sum <= k)
		{
			sum += vec[i];
			++cnt;
		}
	}

	cout << cnt;
}