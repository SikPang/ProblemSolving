#include <iostream>
#include <vector>
using namespace std;

void fillAround(vector< vector<int> >& map, int row, int col)
{
	int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

	for (int i=0; i<8; ++i)
	{
		int nextRow = row + dir[i][0];
		int nextCol = col + dir[i][1];
	
		if (nextRow >= 0 && nextRow < map.size()
			&& nextCol >= 0 && nextCol < map.size()
			&& map[nextRow][nextCol] != -1)
			++map[nextRow][nextCol];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector< vector<int> > map;
	int answer = 0;
	int len, target;
	cin >> len >> target;

	map.resize(len);
	for (int i = 0; i < len; ++i)
	{
		map[i].resize(len);
		for (int j = 0; j < len; ++j)
		{
			int input;
			cin >> input;

			map[i][j] = input * -1;
		}
	}

	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if (map[i][j] == -1)
				fillAround(map, i, j);
	
	for (int i = 0; i < len; ++i)
		for (int j = 0; j < len; ++j)
			if (map[i][j] == target)
				++answer;

	cout << answer << "\n";
}