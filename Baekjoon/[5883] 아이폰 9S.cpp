#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> list(n);
	unordered_set<int> num;
	for (int i=0; i<n; ++i)
	{
		cin >> list[i];
		num.insert(list[i]);
	}

	int max = 0;
	for (unordered_set<int>::iterator iter=num.begin(); iter != num.end(); ++iter)
	{
		int cnt = 0;
		int curNum = -1;
		for (int i=0; i<list.size(); ++i)
		{
			if (list[i] == *iter)
				continue;

			if (curNum == list[i])
				++cnt;
			else
			{
				cnt = 1;
				curNum = list[i];
			}
			if (cnt > max)
				max = cnt;
		}
	}
	cout << max << "\n";
}