#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
#include <math.h>

using namespace std;

struct Edge{
    int node;
    int type;
    Edge(int node, int type)
        : node(node), type(type) {}
};

struct Snapshot{
    vector<int> activeNodes;
    vector<bool> isVisited;
    int infectedCount;
    int openCount;
    Snapshot(vector<int> activeNodes, vector<bool> isVisited, int infectedCount, int openCount)
        : activeNodes(activeNodes), isVisited(isVisited), infectedCount(infectedCount), openCount(openCount) {}
    Snapshot(const Snapshot& other)
        : activeNodes(other.activeNodes), isVisited(other.isVisited), infectedCount(other.infectedCount), openCount(other.openCount) {}
};

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    vector<vector<Edge>> graph(n+1);
    int maxInfection = 0;

    for (int i=0; i<edges.size(); ++i){
        int start = edges[i][0];
        int end = edges[i][1];
        int type = edges[i][2];
        graph[start].push_back(Edge(end, type));
        graph[end].push_back(Edge(start, type));
    }

    queue<Snapshot> que;
    Snapshot first = Snapshot(vector<int>{infection}, vector<bool>(n+1), 1, 0);
    first.isVisited[infection] = true;
    que.push(std::move(first));
    
    while (!que.empty()){
        Snapshot cur = std::move(que.front());
        que.pop();

        for (int type=1; type<=3; ++type){
            Snapshot next(cur);
            ++next.openCount;

            for (int i=0; i<next.activeNodes.size(); ++i){
                vector<Edge>& edges = graph[next.activeNodes[i]];

                for (int j=0; j<edges.size(); ++j){
                    if (edges[j].type == type && !next.isVisited[edges[j].node]) {
                        next.isVisited[edges[j].node] = true;
                        next.activeNodes.push_back(edges[j].node);
                        ++next.infectedCount;
                    }
                }
            }
            
            if (next.infectedCount == n){
                return n;
            }
            
            if (next.openCount == k){
                maxInfection = max(next.infectedCount, maxInfection);
                continue;
            }

            if (!next.activeNodes.empty()){
                que.push(std::move(next));
            }
        }
    }
    return maxInfection;
}