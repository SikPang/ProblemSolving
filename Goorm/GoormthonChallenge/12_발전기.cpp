#include <vector>
#include <iostream>
#include <queue>
using namespace std;

void bfs(vector< vector<int> >& map, int y, int x)
{
	const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	queue< pair<int, int> > que;
	que.push(make_pair(y, x));

	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();

		for (int i=0; i<4; ++i)
		{
			pair<int, int> next(cur.first+dir[i][0], cur.second+dir[i][1]);

			if (next.first >= 0 && next.first < map.size()
				&& next.second >= 0 && next.second < map[0].size()
				&& map[next.first][next.second] == 1)
			{
				map[next.first][next.second] = 2;
				que.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

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

	int answer = 0;
	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
		{
			if (map[i][j] == 1)
			{
				bfs(map, i, j);
				++answer;
			}
		}
	}
	cout << answer << "\n";
}