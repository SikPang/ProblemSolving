class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if ((i==0 && j==0) || obstacleGrid[i][j] == 1) continue;
                // dp[i][j] 에 도착하는 경로는 위에서 오는 것과 왼쪽에서 오는 것 두 가지 뿐이기 때문
                int up = i == 0 ? 0 : dp[i-1][j];
                int left = j == 0 ? 0 : dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[m-1][n-1];
    }
};