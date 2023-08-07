#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<string>& maps, vector<string>& isVisited, int i, int j, vector<int>& answer)
{
	queue< pair<int, int> > que;
	const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int sum = 0;

	que.push(make_pair(i,j));
	isVisited[i][j] = 1;

	while (!que.empty())
	{
		pair<int, int> curPos = que.front();
		que.pop();
		sum += maps[curPos.first][curPos.second] - '0';

		for (int k = 0; k < 4; ++k)
		{
			int nextI = curPos.first + dir[k][0];
			int nextJ = curPos.second + dir[k][1];

			if (nextI < maps.size() && nextJ < maps[i].length()
				&& nextI >= 0 && nextJ >= 0
				&& maps[nextI][nextJ] != 'X' && isVisited[nextI][nextJ] == 0)
			{
				que.push(make_pair(nextI,nextJ));
				isVisited[nextI][nextJ] = 1;
			}
		}
	}
	answer.push_back(sum);
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
	vector<string> isVisited(maps.size());
	const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	for (int i = 0; i < isVisited.size(); ++i)
		isVisited[i].resize(maps[i].length());

	for (int i = 0; i < maps.size(); ++i)
	{
		for (int j = 0; j < maps[i].length(); ++j)
		{
			if (maps[i][j] != 'X' && isVisited[i][j] == 0)
				bfs(maps, isVisited, i, j, answer);
		}
	}
	sort(answer.begin(), answer.end());
	if (answer.empty())
		answer.push_back(-1);
    return answer;
}