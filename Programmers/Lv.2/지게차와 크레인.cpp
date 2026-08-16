#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<string> storage, vector<string> requests) {
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<char>> map(storage.size()+2, vector<char>(storage[0].size()+2, ' '));
    int count = 0;

    for (int i=1; i<storage.size()+1; ++i){
        for (int j=1; j<storage[0].size()+1; ++j){
            map[i][j] = storage[i-1][j-1];
        }
    }

    for (int i=0; i<requests.size(); ++i){
        vector<vector<bool>> isVisited(map.size(), vector<bool>(map[0].size()));
        queue<pair<int, int>> que;
        char target = requests[i][0];

        if (requests[i].size() == 1) {
            que.push(make_pair(0, 0));
            isVisited[0][0] = true;

            while (!que.empty()){
                pair<int, int> cur = que.front();
                que.pop();

                for (int j=0; j<dir.size(); ++j){
                    pair<int, int> next = make_pair(cur.first + dir[j].first, cur.second + dir[j].second);

                    if (next.first < 0 || next.first >= map.size() || next.second < 0 || next.second >= map[0].size()) continue;
                    if (isVisited[next.first][next.second]) continue;

                    isVisited[next.first][next.second] = true;
                    char& elem = map[next.first][next.second];
                    if (elem == ' ') {
                        que.push(next);
                    } else if(elem == target){
                        elem = ' ';
                        ++count;
                    }
                }
            }
        } else {
            for (int j=0; j<map.size(); ++j){
                for (int k=0; k<map[0].size(); ++k){
                    if (map[j][k] == target) {
                        map[j][k] = ' ';
                        ++count;
                    }
                }
            }
        }
    }
    return storage.size() * storage[0].size() - count;
}