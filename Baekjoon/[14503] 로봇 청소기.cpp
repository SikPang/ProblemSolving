#include <iostream>
using namespace std;

int map[50][50];

void TurnLeft(int* cur_dir)
{
	switch (*cur_dir)
	{
	case 0:
		*cur_dir = 3;
		break;
	case 1:
		*cur_dir = 0;
		break;
	case 2:
		*cur_dir = 1;
		break;
	case 3:
		*cur_dir = 2;
		break;
	}
}

void SetDir(int cur_dir, int *dir)
{
	switch (cur_dir)
	{
	case 0:
		dir[0] = -1;
		dir[1] = 0;
		break;
	case 1:
		dir[0] = 0;
		dir[1] = 1;
		break;
	case 2:
		dir[0] = 1;
		dir[1] = 0;
		break;
	case 3:
		dir[0] = 0;
		dir[1] = -1;
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int robot_row, robot_col, cur_dir;
	int dir[2] = {};
	int answer = 0;
	bool check;

	cin >> n >> m >> robot_row >> robot_col >> cur_dir;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int temp;
			cin >> temp;
			map[i][j] = temp;
		}
	}
	SetDir(cur_dir, dir);

	while (true)
	{
		if (map[robot_row][robot_col] != 2)
		{
			map[robot_row][robot_col] = 2;
			++answer;
		}
		check = false;

		for (int i = 0; i < 4; ++i)
		{
			TurnLeft(&cur_dir);
			SetDir(cur_dir, dir);

			if (robot_row + dir[0] >= 0 && robot_row + dir[0] < n
				&& robot_col + dir[1] >= 0 && robot_col + dir[1] < m
				&& map[robot_row + dir[0]][robot_col + dir[1]] == 0)
			{
				robot_row += dir[0];
				robot_col += dir[1];
				check = true;
				break;
			}
		}

		if (!check)
		{
			if (robot_row + dir[0] * -1 >= 0 && robot_row + dir[0] * -1 < n
				&& robot_col + dir[1] * -1 >= 0 && robot_col + dir[1] * -1 < m
				&& map[robot_row + dir[0] * -1][robot_col + dir[1] * -1] != 1)
			{
				robot_row += dir[0] * -1;
				robot_col += dir[1] * -1;
			}
			else
				break;
		}
	}

	cout << answer;
}