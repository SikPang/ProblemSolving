#include <vector>
#include <limits.h>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < edge_list.size(); ++i) {
        graph[edge_list[i][0]].push_back(edge_list[i][1]);
        graph[edge_list[i][1]].push_back(edge_list[i][0]);
    }

    // [시간, 최소 수정 횟수]
    vector<vector<int>> dp(gps_log.size(), vector<int>(n + 1, INT_MAX));
    dp[0][gps_log.front()] = 0;

    for (int time = 1; time < gps_log.size(); ++time) {
        for (int cur = 1; cur <= n; ++cur) {
            // 그대로 머물렀을 경우
            dp[time][cur] = dp[time - 1][cur];

            for (int i=0; i<graph[cur].size(); ++i){
                // 양방향이니까 prev로 사용 가능
                int prev = graph[cur][i];
                dp[time][cur] = min(dp[time][cur], dp[time - 1][prev]);
            }

            // 실제로 달랐을 경우 수정 + 1
            if (dp[time][cur] != INT_MAX && cur != gps_log[time]) {
                ++dp[time][cur];
            }
        }
    }

    int answer = dp.back()[gps_log.back()];
    return answer == INT_MAX ? -1 : answer;
}