#include <queue>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
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
				cout << que.top() << '\n';
				que.pop();
			}
			else
				cout << 0 << '\n';
		}
		else
			que.push(input);
	}
}