#include <vector>
using namespace std;

void dfs(vector<vector<int>>& computers, vector<vector<bool>>& isVisited, int cur)
{
    isVisited[cur][cur] = true;
    for (int i=0; i<computers[cur].size(); ++i)
    {
        if (isVisited[cur][i] || computers[cur][i] == 0) continue;
        
        isVisited[cur][i] = true;
        isVisited[i][cur] = true;
        dfs(computers, isVisited, i);
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<vector<bool>> isVisited(n, vector<bool>(n));
    int answer = 0;
    
    for (int i=0; i<n; ++i)
    {
        if (isVisited[i][i]) continue;

        dfs(computers, isVisited, i);
        ++answer;
    }
    return answer;
}