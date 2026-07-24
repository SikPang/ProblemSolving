class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<bool>> isVisited(matrix.size(), vector<bool>(matrix[0].size()));
        vector<int> ret;
        ret.reserve(matrix.size() * matrix[0].size());
        ret.push_back(matrix[0][0]);
        isVisited[0][0] = true;
        int x = 0;
        int y = 0;

        while (true){
            bool isMoved = false;
            int xDir = x+1 <= matrix[0].size()/2 ? 1 : -1;
            int nextX = x + xDir;

            while (nextX >= 0 && nextX < matrix[0].size() && !isVisited[y][nextX]){
                ret.push_back(matrix[y][nextX]);
                isVisited[y][nextX] = true;
                nextX += xDir;
                isMoved = true;
            }
            x = nextX - xDir;

            int yDir = y+1 <= matrix.size()/2 ? 1 : -1;
            int nextY = y + yDir;
            while (nextY >= 0 && nextY < matrix.size() && !isVisited[nextY][x]){
                ret.push_back(matrix[nextY][x]);
                isVisited[nextY][x] = true;
                nextY += yDir;
                isMoved = true;
            }
            y = nextY - yDir;

            if (!isMoved) break;
        }
        return ret;
    }
};