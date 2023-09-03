#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void dfs(vector<int>& list, vector<int> buf, set< vector<int> >& dup, int depth, int m, int idx)
{
	if (depth == m)
	{
		if (dup.find(buf) != dup.end())
			return;
		for (int i=0; i<buf.size(); ++i)
			cout << buf[i] << " ";
		cout << "\n";
		dup.insert(buf);
		return;
	}

	for (int i=idx; i<list.size(); ++i)
	{
		buf[depth] = list[i];
		dfs(list, buf, dup, depth + 1, m, i);
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

	vector<int> buf(m);
	set< vector<int> > dup;
	dfs(list, buf, dup, 0, m, 0);
}