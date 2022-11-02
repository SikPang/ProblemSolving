#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<int, int> map;
	priority_queue<int> que;
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; ++i)
	{
		int input;
		cin >> input;

		if (input == 0)
		{
			if (!que.empty())
			{
				if (map.find(que.top()) != map.end())
				{
					cout << que.top() << '\n';
					int temp = map[que.top()];
					map.erase(que.top());
					if (temp != 1)
						map.insert({ que.top(), temp - 1 });
				}
				else
				{
					cout << -que.top() << '\n';
					int temp = map[-que.top()];
					map.erase(-que.top());
					if (temp != 1)
						map.insert({ -que.top(), temp - 1 });
				}
				que.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
		{
			if (input > 0)
				que.push(-input);
			else
				que.push(input);

			if (map.find(input) != map.end())
			{
				int temp = map[input];
				map.erase(input);
				map.insert({ input, temp + 1 });
			}
			else
				map.insert({ input, 1 });
		}
	}
}