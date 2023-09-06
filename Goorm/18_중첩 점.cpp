#include <vector>
#include <iostream>
using namespace std;

struct Tile
{
	int vertical;
	int horizontal;
	Tile() : vertical(0), horizontal(0) {}
};

pair<int, int> getDir(char dir)
{
	switch(dir)
	{
	case 'U':
		return make_pair(-1, 0);
	case 'D':
		return make_pair(1, 0);
	case 'L':
		return make_pair(0, -1);
	case 'R':
		return make_pair(0, 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unsigned long long answer = 0;
	int n, m;
	cin >> n >> m;

	vector< vector<Tile> > board(n);
	for (int i=0; i<n; ++i)
		board[i].resize(n);

	for (int i=0; i<m; ++i)
	{
		int y, x;
		char d;

		cin >> y >> x >> d;
		--y;
		--x;

		pair<int, int> dir = getDir(d);
		while ((dir.first == 0 && (x >= 0 && x < n)) || (dir.second == 0 && (y >= 0 && y < n)))
		{
			if (dir.first == 0)
			{
				answer += board[y][x].vertical;
				++board[y][x].horizontal;
			}
			else if (dir.second == 0)
			{
				answer += board[y][x].horizontal;
				++board[y][x].vertical;
			}
			y += dir.first;
			x += dir.second;
		}
	}
	cout << answer << "\n";
}