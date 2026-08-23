#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

void GetRoutes(vector<vector<string>>& answers, unordered_map<string, vector<pair<string, bool>>>& graph, vector<string>& buffer, string cur, int depth){
    if (depth == buffer.size()){
        answers.push_back(buffer);
        return;
    }

    vector<pair<string, bool>>& next = graph[cur];
    for (int i=0; i<next.size(); ++i){
        if (next[i].second) continue;
        next[i].second = true;
        buffer[depth] = next[i].first;
        GetRoutes(answers, graph, buffer, next[i].first, depth+1);
        next[i].second = false;
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<vector<string>> answers;
    unordered_map<string, vector<pair<string, bool>>> graph;
    
    for (int i=0; i<tickets.size(); ++i){
        string& a = tickets[i][0];
        string& b = tickets[i][1];
        graph[a].push_back({b, false});
    } 
    
    vector<string> buffer(tickets.size() + 1);
    buffer[0] = "ICN";
    
    GetRoutes(answers, graph, buffer, "ICN", 1);

    sort(answers.begin(), answers.end());

    return answers[0];
}