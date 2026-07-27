class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i=1; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                // dp[i][j] 에 도착하는 경로는 위에서 오는 것과 왼쪽에서 오는 것 두 가지 뿐이기 때문
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};