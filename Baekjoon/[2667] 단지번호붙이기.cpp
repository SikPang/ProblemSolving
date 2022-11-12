#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

int map[25][25];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<pair<int, int>> que;
	vector<int> answer;
	int direction[4][2] = { {-1, 0},{1, 0},{0, -1},{0, 1} };

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string input;
		cin >> input;

		for (int j = 0; j < n; ++j)
			map[i][j] = input[j];
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (map[i][j] == '1')
			{
				int area = 0;
				que.push({i, j});
				map[i][j] = '2';

				while (!que.empty())
				{
					int row = que.front().first;
					int col = que.front().second;

					for (int k = 0; k < 4; ++k)
					{
						int nextRow = row + direction[k][0];
						int nextCol = col + direction[k][1];
						if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < n 
							&& map[nextRow][nextCol] == '1')
						{
							que.push( { nextRow, nextCol });
							map[nextRow][nextCol] = '2';
						}
					}

					que.pop();
					++area;
				}
				answer.push_back(area);
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << '\n';
}