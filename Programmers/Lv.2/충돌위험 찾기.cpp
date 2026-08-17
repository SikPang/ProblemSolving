#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<pair<int, int>> GetRoute(vector<vector<int>>& points, vector<int>& routePoints) {
    vector<pair<int, int>> route;

    for (int i = 0; i < routePoints.size() - 1; ++i) {
        vector<int>& start = points[routePoints[i] - 1];
        vector<int>& end = points[routePoints[i + 1] - 1];

        int r = start[0];
        int c = start[1];

        if (route.empty()) {
            route.push_back({r, c});
        }

        while (r != end[0]) {
            r += r < end[0] ? 1 : -1;
            route.push_back({r, c});
        }

        while (c != end[1]) {
            c += c < end[1] ? 1 : -1;
            route.push_back({r, c});
        }
    }
    return route;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    vector<vector<pair<int, int>>> shortestRoutes;
    int maxLen = 0;
    for (int i=0; i<routes.size(); ++i){
        vector<pair<int, int>> route = GetRoute(points, routes[i]);
        maxLen = max((int)route.size(), maxLen);
        shortestRoutes.push_back(route);
    }

    for (int time=0; time<maxLen; ++time){
        map<pair<int, int>, int> map;
        for (int i=0; i<shortestRoutes.size(); ++i){
            if (shortestRoutes[i].size() <= time) continue;
            ++map[shortestRoutes[i][time]];
        }

        for(auto iter = map.begin(); iter != map.end(); ++iter){
            if (iter->second > 1) ++answer;
        }
    }
    return answer;
}