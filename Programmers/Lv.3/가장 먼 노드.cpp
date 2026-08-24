#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n+1);
    vector<int> minDistance(n+1, INT_MAX);
    
    for (int i=0; i<edge.size(); ++i){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }
    
    queue<pair<int, int>> que;
    que.push({1, 0});
    minDistance[1] = 0;
    
    while (!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        
        vector<int>& next = graph[cur.first];
        int nextDist = cur.second + 1;
        for (int i=0; i<next.size(); ++i){
            if (minDistance[next[i]] <= nextDist) continue;
            
            minDistance[next[i]] = nextDist;
            que.push({next[i], nextDist});
        }
    }

    int maxValue = *max_element(minDistance.begin()+1, minDistance.end());
    int count = 0;
    for (int i=0; i<n+1; ++i){
        if (minDistance[i] == maxValue){
            ++count;
        }
    }
    return count;
}