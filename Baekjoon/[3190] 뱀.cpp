#include <deque>
#include <queue>
#include <iostream>
using namespace std;

int map[100][100] = {};

void ChangeDirection(int *cur_dir, char dir)
{
	int direct;

	if (dir == 'L')
		direct = 1;
	else
		direct = -1;

	if (cur_dir[0] == 0 && cur_dir[1] == 1)
	{
		cur_dir[0] = -1 * direct;
		cur_dir[1] = 0;
	}
	else if (cur_dir[0] == 0 && cur_dir[1] == -1)
	{
		cur_dir[0] = 1 * direct;
		cur_dir[1] = 0;
	}
	else if (cur_dir[0] == 1 && cur_dir[1] == 0)
	{
		cur_dir[0] = 0;
		cur_dir[1] = 1 * direct;
	}
	else if (cur_dir[0] == -1 && cur_dir[1] == 0)
	{
		cur_dir[0] = 0;
		cur_dir[1] = -1 * direct;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<pair<int, int>> snake;
	queue<pair<int, char>> que;
	int map_size, apple_num, move_num;
	int cur_dir[2] = { 0, 1 };
	int cur_pos[2] = { 0, 0 };
	int cur_sec = 0;

	cin >> map_size >> apple_num;

	for (int i = 0; i < apple_num; ++i)
	{
		int apple_row, apple_col;
		cin >> apple_row >> apple_col;

		map[apple_row - 1][apple_col - 1] = 1;
	}

	cin >> move_num;

	for (int i = 0; i < move_num; ++i)
	{
		int sec;
		char dir;
		cin >> sec >> dir;

		que.push({ sec, dir });
	}

	map[0][0] = 2;
	snake.push_front({0, 0});

	while (true)
	{
		if (!que.empty() && que.front().first == cur_sec)
		{
			ChangeDirection(cur_dir, que.front().second);
			que.pop();
		}
		
		cur_pos[0] += cur_dir[0];
		cur_pos[1] += cur_dir[1];
		++cur_sec;

		if (cur_pos[0] >= 0 && cur_pos[0] < map_size && cur_pos[1] >= 0 && cur_pos[1] < map_size
			&& map[cur_pos[0]][cur_pos[1]] != 2)
		{
			snake.push_front({ cur_pos[0], cur_pos[1] });

			if (map[cur_pos[0]][cur_pos[1]] == 0)
			{
				map[snake.back().first][snake.back().second] = 0;
				snake.pop_back();
			}

			map[cur_pos[0]][cur_pos[1]] = 2;
		}
		else
			break;
	}

	cout << cur_sec;
}