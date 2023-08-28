#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int bfs(vector<string>& board, int y, int x)
{
	const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	queue< tuple<int, int, int> > que;

	que.push(tuple<int, int, int>{y, x, 0});
	board[y][x] = 'V';

	while (!que.empty())
	{
		tuple<int, int, int> cur = que.front();
		que.pop();

		for (int i=0; i<4; ++i)
		{
			int nextY = get<0>(cur) + dir[i][0];
			int nextX = get<1>(cur) + dir[i][1];

			while (nextY >= 0 && nextY < board.size() 
				&& nextX >= 0 && nextX < board[0].length()
				&& board[nextY][nextX] != 'D')
			{
				nextY += dir[i][0];
				nextX += dir[i][1];
			}
			nextY -= dir[i][0];
			nextX -= dir[i][1];
			if (board[nextY][nextX] == 'G')
				return get<2>(cur) + 1;
			else if (board[nextY][nextX] == 'V')
				continue;
			board[nextY][nextX] = 'V';
			que.push(tuple<int, int, int>{nextY, nextX, get<2>(cur) + 1});
		}
	}
	return -1;
}

int solution(vector<string> board) {
	for (int i=0; i<board.size(); ++i)
		for (int j=0; j<board[i].length(); ++j)
			if (board[i][j] == 'R')
				return bfs(board, i, j);
}