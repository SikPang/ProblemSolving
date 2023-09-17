#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long num;
	cin >> num;

	long long cur=0, cnt=0, i=1;
	while (true)
	{
		cur += i;
		++cnt;
		++i;

		if (cur > num)
			break;
	}
	cout << cnt - 1 << "\n";
}