#include <vector>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector< pair<int, int> > info;
	vector<int> rate;
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		info.push_back(make_pair(a, b));
		rate.push_back(0);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j == i) continue;

			bool a = false, b = false;

			if (info[j].first > info[i].first)
				a = true;
			if (info[j].second > info[i].second)
				b = true;
			if (a && b)
				++rate[i];
		}
	}

	for (int i = 0; i < n; ++i)
		cout << rate[i] + 1 << ' ';
}