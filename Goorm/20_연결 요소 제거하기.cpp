#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void fill(vector< vector<char> >& map, vector< vector<bool> > isVisited, int y, int x, char d, int k)
{
	int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	queue< pair<int, int> > que;
	vector< pair<int, int> > buf;

	que.push(make_pair(y, x));
	buf.push_back(make_pair(y, x));
	map[y][x] = d;
	isVisited[y][x] = true;
	int cnt = 1;

	while (!que.empty())
	{
		pair<int, int> cur = que.front();
		que.pop();

		for (int i=0; i<4; ++i)
		{
			pair<int, int> nextjs(cur.first + dir[i][0], cur.second + dir[i][1]);

			if (nextjs.first >= 0 && nextjs.first < map.size()
				&& nextjs.second >= 0 && nextjs.second < map.size()
				&& map[nextjs.first][nextjs.second] == d
				&& !isVisited[nextjs.first][nextjs.second])
			{
				que.push(make_pair(nextjs.first, nextjs.second));
				buf.push_back(make_pair(nextjs.first, nextjs.second));
				isVisited[nextjs.first][nextjs.second] = true;
				++cnt;
			}
		}
	}

	if (buf.size() < k)
		return;

	for (int i=0; i<buf.size(); ++i)
		map[buf[i].first][buf[i].second] = '.';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, q;
	cin >> n >> k >> q;

	vector< vector<char> > map(n);
	vector< vector<bool> > isVisited(n);
	for (int i=0; i<n; ++i)
	{
		map[i].resize(n);
		isVisited[i].resize(n);
	}

	for (int i=0; i<n; ++i)
		for (int j=0; j<n; ++j)
			cin >> map[i][j];
	
	for (int i=0; i<q; ++i)
	{
		int y, x;
		char d;
		cin >> y >> x >> d;
		fill(map, isVisited, y - 1, x - 1, d, k);
	}

	for (int i=0; i<n; ++i)
	{
		for (int j=0; j<n; ++j)
			cout << map[i][j];
		cout << "\n";
	}
}