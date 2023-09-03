#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& list, vector<int>& buf, int depth, int m, int idx)
{
	if (depth == m)
	{
		for (int i=0; i<buf.size(); ++i)
			cout << buf[i] << " ";
		cout << "\n";
		return;
	}

	for (int i=idx; i<list.size(); ++i)
	{
		buf[depth] = list[i];
		dfs(list, buf, depth + 1, m, i);
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
	vector<bool> isUsed(n);
	dfs(list, buf, 0, m, 0);
}