#include <stack>
#include <iostream>
using namespace std;

int answer[1000000] = {};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	stack<pair<int, int>> stack;
	int num;
	cin >> num;

	for (int i = 0; i < num; ++i)
	{
		int input;
		cin >> input;

		while (!stack.empty() && input > stack.top().first)
		{
			answer[stack.top().second] = input;
			stack.pop();
		}

		stack.push({ input, i });
	}
	
	for (int i = 0; i < num; ++i)
	{
		if (answer[i] == 0)
			cout << -1 << ' ';
		else
			cout << answer[i] << ' ';
	}
}