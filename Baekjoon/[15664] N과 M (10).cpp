#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& list, string& buf, vector<bool>& isUsed, unordered_set<string>& dup, int depth, int m, int idx)
{
	if (depth == m)
	{
		if (dup.find(buf) != dup.end())
			return;
		for (int i=0; i<buf.size(); ++i)
			cout << static_cast<int>(buf[i]) << " ";
		cout << "\n";
		dup.insert(buf);
		return;
	}

	for (int i=idx; i<list.size(); ++i)
	{
		if (isUsed[i])
			continue;
		
		isUsed[i] = true;
		buf[depth] = list[i];
		dfs(list, buf, isUsed, dup, depth + 1, m, i + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> list(n);
	for (int i=0; i<n; ++i)
		cin >> list[i];
	sort(list.begin(), list.end());

	string buf;
	buf.resize(m);
	vector<bool> isUsed(n);
	unordered_set<string> dup;
	dfs(list, buf, isUsed, dup, 0, m, 0);
}