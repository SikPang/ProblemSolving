#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void dfs(int depth, string& input, vector<string>& sel, vector< vector<string> >& list, map<string, int>& myMap, int cur)
{
	if (depth == 3)
	{
		if (cur == input.length())
		{
			for (int i=0; i<3; ++i)
				myMap.insert(make_pair(sel[i], 0));
			list.push_back(sel);
		}
		return;
	}

	for (int i=cur; i<input.length(); ++i)
	{
		sel[depth].push_back(input[i]);
		dfs(depth + 1, input, sel, list, myMap, i + 1);
	}
	sel[depth].clear();
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int num;
	cin >> num;

	string str;
	cin >> str;

	vector<string> sel(3);
	vector< vector<string> > list;
	map<string, int> myMap;
	dfs(0, str, sel, list, myMap, 0);

	int val = 0;
	for (map<string, int>::iterator iter = myMap.begin(); iter != myMap.end(); ++iter)
		iter->second = ++val;

	int maxVal = 0;
	for (int i=0; i<list.size(); ++i)
	{
		int sum = 0;
		for (int j=0; j<3; ++j)
			sum += myMap.find(list[i][j])->second;
		maxVal = max(maxVal, sum);
	}
	cout << maxVal << "\n";
}