#include <string>
#include <vector>
#include <queue>
#define DIR_LENGTH 4

using namespace std;

struct Pos
{
	int x;
	int y;
	int steps;
	Pos(int y, int x, int steps)
		: y(y), x(x), steps(steps) {}
};

int bfs(vector<string> maps, pair<int, int> start, char target)
{
	int dir[DIR_LENGTH][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	queue<Pos> que;

	maps[start.first][start.second] = 'X';
	que.push(Pos(start.first, start.second, 0));
	while (!que.empty())
	{
		Pos cur = que.front();
		que.pop();

		for (int i=0; i<DIR_LENGTH; ++i)
		{
			Pos next(cur.y + dir[i][0], cur.x + dir[i][1], cur.steps + 1);
			
			if (next.y >= 0 && next.y < maps.size()
				&& next.x >= 0 && next.x < maps[0].size()
				&& maps[next.y][next.x] != 'X')
			{
				if (maps[next.y][next.x] == target)
					return next.steps;
				maps[next.y][next.x] = 'X';
				que.push(next);
			}
		}
	}
	return -1;
}

int solution(vector<string> maps) {
	pair<int, int> lever;
	pair<int, int> start;

	for (int i=0; i<maps.size(); ++i)
	{
		for (int j=0; j<maps[i].size(); ++j)
		{
			if (maps[i][j] == 'L')
				lever = pair<int, int>(i, j);
			if (maps[i][j] == 'S')
				start = pair<int, int>(i, j);
		}
	}

	int toLever = bfs(maps, start, 'L');
	int toExit = bfs(maps, lever, 'E');

	if (toLever == -1 || toExit == -1)
	    return -1;
	return toLever + toExit;
}
