#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int GetBattleCount(vector<vector<pair<int, bool>>>& graph, int target, bool isWin){
    queue<int> que;
    unordered_set<int> isVisited;
    
    que.push(target);
    isVisited.insert(target);
    
    while (!que.empty()){
        int cur = que.front();
        que.pop();
        
        vector<pair<int, bool>>& next = graph[cur];
        for (int i=0; i<next.size(); ++i){
            if (next[i].second != isWin || isVisited.contains(next[i].first)) continue;
            
            que.push(next[i].first);
            isVisited.insert(next[i].first);
        }
    }
    return isVisited.size() - 1;
}

int solution(int n, vector<vector<int>> results) {
    vector<vector<pair<int, bool>>> graph(n+1);
    int answer =0;
    
    for (int i=0; i<results.size(); ++i){
        int a = results[i][0];
        int b = results[i][1];

        graph[a].push_back({b, true});
        graph[b].push_back({a, false});
    }
    
    for (int i=1; i<=n; ++i){
        int total = GetBattleCount(graph, i, true) + GetBattleCount(graph, i, false);
        if (total == n - 1) {
            ++answer;
        }
    }
    return answer;
}