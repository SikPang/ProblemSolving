class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int rowSum = 0;
        int colSum = 0;
        int area = 0;

        for (int i=0; i<grid.size(); ++i){
            int maxH = 0;
            for (int j=0; j<grid[i].size(); ++j){
                maxH = max(maxH, grid[i][j]);
                area += grid[i][j] > 0 ? 1 : 0;
            }
            rowSum += maxH;
        }

        for (int i=0; i<grid[0].size(); ++i){
            int maxH = 0;
            for (int j=0; j<grid.size(); ++j){
                maxH = max(maxH, grid[j][i]);
            }
            colSum += maxH;
        }
        return rowSum + colSum + area;
    }
};
