#include <queue>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		queue<pair<int, int>> docs;
		priority_queue<int> prios;
		int num, target;
		int count = 0;

		cin >> num >> target;

		for (int j = 0; j < num; ++j)
		{
			int priority;
			cin >> priority;

			docs.push({ j, priority });
			prios.push(priority);
		}

		while (!docs.empty())
		{
			if (docs.front().second == prios.top())
			{
				if (docs.front().first == target)
				{
					cout << count + 1 << '\n';
					break;
				}
				++count;
				prios.pop();
				docs.pop();
			}
			else
			{
				pair<int, int> temp = docs.front();
				docs.pop();
				docs.push(temp);
			}
		}
	}
}