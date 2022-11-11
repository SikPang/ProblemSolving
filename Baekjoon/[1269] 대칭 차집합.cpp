#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<int, bool> map;
	int a, b;
	int answer;

	cin >> a >> b;
	answer = a + b;

	for (int i = 0; i < a; ++i)
	{
		int input;
		cin >> input;

		map.insert({ input, true });
	}
	for (int i = 0; i < b; ++i)
	{
		int input;
		cin >> input;

		if (map[input] == true)
			answer -= 2;
	}

	cout << answer;
}