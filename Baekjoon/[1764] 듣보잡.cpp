#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<string, bool> map;
	vector<string> list;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string input;
		cin >> input;

		map.insert({input, true});
	}

	for (int i = 0; i < m; ++i)
	{
		string input;
		cin >> input;

		if (map.find(input) != map.end())
			list.push_back(input);
	}

	sort(list.begin(), list.end());

	cout << list.size() << '\n';
	for (int i = 0; i < list.size(); ++i)
		cout << list[i] << '\n';
}