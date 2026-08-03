class Solution {
private:
    void setZeroesRowRecur(vector<vector<int>>& matrix, vector<bool>& rowUsed, vector<bool>& colUsed, int y, int x){
        for (int i=0; i<matrix[0].size(); ++i){
            if (matrix[y][i] == 0 && !colUsed[i]) {
                colUsed[i] = true;
                setZeroesColRecur(matrix, rowUsed, colUsed, y, i);
            }
            matrix[y][i] = 0;
        }
    }

    void setZeroesColRecur(vector<vector<int>>& matrix, vector<bool>& rowUsed, vector<bool>& colUsed, int y, int x){
        for (int i=0; i<matrix.size(); ++i){
            if (matrix[i][x] == 0 && !rowUsed[i]) {
                rowUsed[i] = true;
                setZeroesRowRecur(matrix, rowUsed, colUsed, i, x);
            }
            matrix[i][x] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> rowUsed = vector<bool>(matrix.size());
        vector<bool> colUsed = vector<bool>(matrix[0].size());

        for (int i=0; i<matrix.size(); ++i){
            for (int j=0; j<matrix[0].size(); ++j){
                if (matrix[i][j] != 0) continue;

                if (rowUsed[i] || colUsed[j]) continue;

                rowUsed[i] = true;
                colUsed[j] = true;

                setZeroesRowRecur(matrix, rowUsed, colUsed, i, j);
                setZeroesColRecur(matrix, rowUsed, colUsed, i, j);
            }
        }
    }
};