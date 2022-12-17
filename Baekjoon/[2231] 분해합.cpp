#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		int temp = i;
		int sum = i;
		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
}
