class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> ret(grid.size(), vector<int>(grid[0].size()));
        queue<int> buffer;

        for (int i=grid.size()-1; i>=0; --i){
            for (int j=grid[0].size()-1; j>=0; --j){
                buffer.push(grid[i][j]);
            }
        }

        for (int i=0; i<k; ++i){
            int next = buffer.front();
            buffer.pop();
            buffer.push(next);
        }

        int idx = grid.size() * grid[0].size()-1;
        while (!buffer.empty()){
            int next = buffer.front();
            buffer.pop();

            int row = idx / grid[0].size();
            int col = idx % grid[0].size();
            ret[row][col] = next;
            --idx;
        }
        return ret;
    }
};