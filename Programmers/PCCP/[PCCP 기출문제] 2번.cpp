#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int maps[501] = {};

void bfs(vector<vector<int>>& land, int* maps)
{
    queue<pair<int, int>> que;
    const int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};
    
    for (int i=0; i<land.size(); ++i)
    {
        for (int j=0; j<land[0].size(); ++j)
        {
            if (land[i][j] == 1)
            {
                set<int> set;
                que.push(make_pair(i, j));
                set.insert(j);
                int cnt = 1;
                land[i][j] = 2;
                
                while (!que.empty())
                {
                    pair<int, int> cur = que.front();
                    que.pop();

                    for (int k=0; k<4; ++k)
                    {
                        pair<int, int> next(cur.first+dir[k][0], cur.second+dir[k][1]);

                        if (next.first>=0 && next.first<land.size() &&
                           next.second>=0 && next.second<land[0].size() &&
                           land[next.first][next.second] == 1)
                        {
                            set.insert(next.second);
                            land[next.first][next.second] = 2;
                            que.push(next);
                            ++cnt;
                        }
                    }
                }
                
                for (auto iter=set.begin(); iter!=set.end(); ++iter)
                    maps[*iter] += cnt;
            }
        }
    }
}

int solution(vector<vector<int>> land) {
    int maxx = 0;
    int maps[501] = {};
    
    bfs(land, maps);
    for (int i=0; i<501; ++i)
    {
        if (maps[i] > maxx)
            maxx = maps[i];
    }
    return maxx;
}