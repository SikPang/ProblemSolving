#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int mapSize, bomb;
	cin >> mapSize >> bomb;

	vector< vector<int> > map(mapSize);
	for (int i=0; i<mapSize; ++i)
		map[i].resize(mapSize);

	vector< vector<int> > value(map);

	for (int i=0; i<mapSize; ++i)
	{
		for (int j=0; j<mapSize; ++j)
		{
			char input;
			cin >> input;
			map[i][j] = static_cast<int>(input);
		}
	}

	const int dir[5][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {0, 0}};
	int max = 0;

	for (int i=0; i<bomb; ++i)
	{
		int y, x;
		cin >> y >> x;

		for (int j=0; j<5; ++j)
		{
			int nextY = y - 1 + dir[j][0];
			int nextX = x - 1 + dir[j][1];

			if (nextY < 0 || nextY >= mapSize || nextX < 0 || nextX >= mapSize)
				continue;
			
			if (map[nextY][nextX] == '0')
				value[nextY][nextX] += 1;
			if (map[nextY][nextX] == '@')
				value[nextY][nextX] += 2;
			
			if (value[nextY][nextX] > max)
				max = value[nextY][nextX];
		}
	}
	cout << max << "\n";
}