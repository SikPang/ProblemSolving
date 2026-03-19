class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) return mat;

        vector<vector<int>> ret(r, vector<int>(c));
        int idx = 0;
        for (int i=0; i<r; ++i){
            for (int j=0; j<c; ++j){
                int row = idx / mat[0].size();
                int col = idx % mat[0].size();
                ret[i][j] = mat[row][col];
                ++idx;
            }
        }
        return ret;
    }
};