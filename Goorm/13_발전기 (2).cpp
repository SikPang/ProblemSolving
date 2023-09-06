#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void bfs(vector< vector<int> >& map, int nums[31], int y, int x, int k)
{
	const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	queue< pair<int, int> > que;
	que.push(make_pair(y, x));
	int category = map[y][x];
	map[y][x] = 0;
	int cnt = 1;
	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();

		for (int i=0; i<4; ++i)
		{
			pair<int, int> next(cur.first+dir[i][0], cur.second+dir[i][1]);

			if (next.first >= 0 && next.first < map.size()
				&& next.second >= 0 && next.second < map[0].size()
				&& map[next.first][next.second] == category)
			{
				map[next.first][next.second] = 0;
				que.push(next);
				++cnt;
			}
		}
	}
	if (cnt >= k)
		++nums[category];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	vector< vector<int> > map(n);

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
		{
			int input;
			cin >> input;
			map[i].push_back(input);
		}
	}

	int nums[31] = {};
	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			if (map[i][j] != 0)
				bfs(map, nums, i, j, k);

	pair<int, int> max = {};
	for (int i=0; i<31; ++i)
	{
		if (max.second <= nums[i])
		{
			max.first = i;
			max.second = nums[i];
		}
	}
	cout << max.first << "\n";
}