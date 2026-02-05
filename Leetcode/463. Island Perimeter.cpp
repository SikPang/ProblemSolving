class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int answer = 0;

        for (int i=0; i<grid.size(); ++i){
            int cur = 0;
            for (int j=0; j<grid[0].size(); ++j){
                if (cur != grid[i][j]){
                    ++answer;
                }
                cur = grid[i][j];
            }
            if (cur == 1) ++answer;
        }

        for (int i=0; i<grid[0].size(); ++i){
            int cur = 0;
            for (int j=0; j<grid.size(); ++j){
                if (cur != grid[j][i]){
                    ++answer;
                }
                cur = grid[j][i];
            }
            if (cur == 1) ++answer;
        }
        return answer;
    }
};