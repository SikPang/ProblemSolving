#include <string>
#include <vector>
#include <limits.h>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size());
    vector<vector<int>> graph(n+1);
    vector<int> minDistance(n+1, INT_MAX);
    
    for (int i=0; i<roads.size(); ++i){
        int a = roads[i][0];
        int b = roads[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    queue<pair<int, int>> que;
    que.push({destination, 0});
    
    while (!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        
        if (minDistance[cur.first] <= cur.second) continue;
        
        minDistance[cur.first] = cur.second;
        
        vector<int> next = graph[cur.first];
        for (int i=0; i<next.size(); ++i){
            que.push({next[i], cur.second+1});
        }
    }
    
    for (int i=0; i<sources.size(); ++i){
        int dist = minDistance[sources[i]];
        answer[i] = dist == INT_MAX ? -1 : dist;
    }
    
    return answer;
}