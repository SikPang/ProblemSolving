#include <string>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& list, string& buf, unordered_set<string>& dup, int depth, int m)
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

	for (int i=0; i<list.size(); ++i)
	{
		buf[depth] = list[i];
		dfs(list, buf, dup, depth + 1, m);
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
	unordered_set<string> dup;
	dfs(list, buf, dup, 0, m);
}