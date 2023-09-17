#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, len;
	cin >> n >> len;

	bool pipe[1001] = {};
	for (int i=0; i<n; ++i)
	{
		int crashPoint;
		cin >> crashPoint;
		pipe[crashPoint] = true;
	}

	int cnt = 0;
	for (int i=0; i<1001; ++i)
	{
		if (pipe[i] == true)
		{
			for (int j=i; j<i+len; ++j)
				pipe[j] = false;
			i = i + len - 1;
			++cnt;
		}
	}
	cout << cnt << "\n";
}