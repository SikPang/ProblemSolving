#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

enum Direction {
	RIGHT, DOWN, LEFT, UP, SIZE
};

const int dir[SIZE][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int Go(int cur, int step, int max) {
	cur += step;
	if (cur == max)
		return 0;
	else if (cur == -1)
		return max-1;
	return cur;
}

void RotateDir(pair<int, int>& step, Direction& curDir, char c) {
	if (c == 'S')
		return;

	if (c == 'L')	// 시계 방향
		curDir = curDir + 1 == SIZE ? (Direction)0 : (Direction)(curDir + 1);
	else if (c == 'R')	// 반시계 방향
		curDir = curDir - 1 == -1 ? (Direction)(SIZE - 1) : (Direction)(curDir - 1);

	step.first = dir[curDir][0];
	step.second = dir[curDir][1];
}

int rayCast(vector<string>& grid, vector<vector<vector<bool>>>& isVisited, pair<int, int> startPos, Direction startDirection) {
	pair<int, int> cur = startPos;
	pair<int, int> step(dir[startDirection][0], dir[startDirection][1]);
	pair<int, int> startDir = step;
	Direction curDir = startDirection;
	int distance = 0;

	do {
		isVisited[cur.first][cur.second][curDir] = true;
		RotateDir(step, curDir, grid[cur.first][cur.second]);

		cur.first = Go(cur.first, step.first, grid.size());
		cur.second = Go(cur.second, step.second, grid[0].size());
		
		++distance;
	} while (cur != startPos || step != startDir);
	return distance;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
	vector<vector<vector<bool>>> isVisited(grid.size(), vector<vector<bool>>(grid[0].size(), vector<bool>(SIZE))); 

	for (int i=0; i<grid.size(); ++i) {
		for (int j=0; j<grid[0].size(); ++j) {
			for (int k=0; k<SIZE; ++k)	{ // Direction
				if (isVisited[i][j][k])
					continue;
				answer.push_back(rayCast(grid, isVisited, pair<int, int>{i, j}, (Direction)k));
			}
		}
	}
	sort(answer.begin(), answer.end());
    return answer;
}