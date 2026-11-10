class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int rowSum = 0;
        int colSum = 0;
        int area = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                area += grid[i][j] > 0 ? 1 : 0;
                rowSum += grid[i][j];

                if (j > 0) {
                    rowSum -= min(grid[i][j], grid[i][j - 1]);
                }
            }
        }

        for (int i = 0; i < grid[0].size(); ++i) {
            for (int j = 0; j < grid.size(); ++j) {
                colSum += grid[j][i];

                if (j > 0) {
                    colSum -= min(grid[j][i], grid[j - 1][i]);
                }
            }
        }
        return (rowSum + colSum + area) * 2;
    }
};