#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int>& list, vector<int>& buf, vector<bool>& isUsed, int depth, int m, int idx)
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
		if (isUsed[i])
			continue;
		
		isUsed[i] = true;
		buf[depth] = list[i];
		dfs(list, buf, isUsed, depth + 1, m, i + 1);
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

	vector<int> buf(m);
	vector<bool> isUsed(n);
	dfs(list, buf, isUsed, 0, m, 0);
}