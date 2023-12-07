#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& picture, vector<vector<bool>>& isVisited, int y, int x)
{
    queue<vector<int>> que;
    const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int area = 1;
    int target = picture[y][x];
    
    que.push(vector<int>{y, x, 0});
    isVisited[y][x] = true;
    while (!que.empty())
    {
        vector<int> cur = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i)
        {
            vector<int> next = {cur[0]+dir[i][0], cur[1]+dir[i][1], cur[2]+1};
            
            if (next[0] >= 0 && next[0] < picture.size() && next[1] >= 0 && next[1] < picture[0].size()
           && picture[next[0]][next[1]] == target && isVisited[next[0]][next[1]] == false)
            {
                isVisited[next[0]][next[1]] = true;
                ++area;
                que.push(next);
            }
        }
    }
    return area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<vector<bool>> isVisited(picture.size(), vector<bool>(picture[0].size(), 0));
    int max = 0;
    int size = 0;
    
    for (int i=0; i<picture.size(); ++i)
    {
        for (int j=0; j<picture[0].size(); ++j)
        {
            if (isVisited[i][j] || picture[i][j] == 0)
                continue;
            ++size;
            int area = bfs(picture, isVisited, i, j);
            if (max < area)
                max = area;
        }
    }
    return vector<int>{size, max};
}