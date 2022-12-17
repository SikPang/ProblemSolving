#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> need;
	vector<int> price;
	unsigned long long sum = 0;

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int input;
		cin >> input;

		need.push_back(input);
	}
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;

		price.push_back(input);
	}

	int i = 0;
	while (i < n - 1)
	{
		long long temp = need[i];
		int j = 1;
		while (price[i] < price[i + j])
		{
			temp += need[i + j];
			++j;
		}
		sum += temp * price[i];
		i += j;
	}

	cout << sum;
}