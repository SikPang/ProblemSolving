#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int i = 666;
	int num = 0;
	while (true)
	{
		int temp = i;
		int cnt = 0;
		while (temp != 0 && cnt < 3)
		{
			if (temp % 10 == 6)
				++cnt;
			else
				cnt = 0;
			temp /= 10;
		}
		if (cnt == 3)
			++num;
		if (num == n)
		{
			cout << i;
			return 0;
		}
		++i;
	}
}