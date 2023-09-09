#include <climits>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;

void dfs(vector< pair<int, int> >& vec, vector<bool>& isUsed, pair<LL, LL> cur, LL& min, int depth)
{
	if (depth == vec.size())
		return;

	for (int i=0; i<vec.size(); ++i)
	{
		if (isUsed[i])
			continue;
		
		isUsed[i] = true;
		pair<LL, LL> next(cur.first * vec[i].first, cur.second + vec[i].second);
		LL diff = next.first - next.second < 0 ? (next.first - next.second) * -1 : next.first - next.second;
		if (diff < min)
			min = diff;
		
		dfs(vec, isUsed, next, min, depth + 1);
		isUsed[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	LL min = LONG_LONG_MAX;
	vector<bool> isUsed(n);
	vector< pair<int, int> > vec(n);
	for (int i=0; i<vec.size(); ++i)
		cin >> vec[i].first >> vec[i].second;

	dfs(vec, isUsed, pair<LL, LL>{1,0}, min, 0);
	cout << min << "\n";
}