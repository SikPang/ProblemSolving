#include <vector>
#define MOD 1000000007

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<long long>> maps(n+1, vector<long long>(m+1));
    
    for (int i=0; i<puddles.size(); ++i)
        maps[puddles[i][1]][puddles[i][0]] = -1;
    maps[1][1] = 1;
    
    for (int i=1; i<maps.size(); ++i)
    {
        for (int j=1; j<maps[0].size(); ++j)
        {
            if (maps[i][j] == -1) continue;
            
            maps[i][j] += maps[i-1][j] == -1 ? 0 : maps[i-1][j];
            maps[i][j] += maps[i][j-1] == -1 ? 0 : maps[i][j-1];
            maps[i][j] %= MOD;
        }
    }
    return maps[n][m];
}