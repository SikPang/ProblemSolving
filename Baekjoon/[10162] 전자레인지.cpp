#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int time;
	cin >> time;

	int cnt[3] = {};
	cnt[0] += time / 300;
	time %= 300;

	cnt[1] += time / 60;
	time %= 60;

	cnt[2] += time / 10;
	time %= 10;

	if (time != 0)
		cout << "-1\n";
	else
		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << "\n";
}