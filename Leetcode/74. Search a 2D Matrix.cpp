class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (m == 1 && n == 1) return matrix[0][0] == target;

        int left = 0;
        int right = n * m - 1;
        cout << target << endl;

        while (right >= left) {
            int center = (right + left) / 2;
            int in2dRow = center / m;
            int in2dCol = center % m;

            if (right - 1 <= left) {
                return matrix[right/m][right%m] == target || matrix[left/m][left%m] == target;
            }

            cout << left << ", " << center << ", " << right << endl;
            cout << "val : " << matrix[in2dRow][in2dCol] << endl;

            if (matrix[in2dRow][in2dCol] == target) return true;

            if (matrix[in2dRow][in2dCol] < target) {
                left = center + 1;
            } else {
                right = center - 1;
            }
        }
        return false;
    }
};