class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); ++i){
            int cur = matrix[i][0];

            for (int col=0, row=i; col<matrix[0].size() && row<matrix.size(); ++col, ++row){
                if (cur != matrix[row][col]) return false;
            }
        }

        for (int i=0; i<matrix[0].size(); ++i){
            int cur = matrix[0][i];

            for (int col=i, row=0; col<matrix[0].size() && row<matrix.size(); ++col, ++row){
                if (cur != matrix[row][col]) return false;
            }
        }
        return true;
    }
};