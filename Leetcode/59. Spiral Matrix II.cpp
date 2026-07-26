class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<vector<bool>> isVisited(n, vector<bool>(n));
        matrix[0][0] = 1;
        isVisited[0][0] = true;
        int x = 0;
        int y = 0;
        int num = 2;

        while (true){
            bool isMoved = false;
            int xDir = x+1 <= n/2 ? 1 : -1;
            int nextX = x + xDir;

            while (nextX >= 0 && nextX < n && !isVisited[y][nextX]){
                matrix[y][nextX] = num++;
                isVisited[y][nextX] = true;
                nextX += xDir;
                isMoved = true;
            }
            x = nextX - xDir;

            int yDir = y+1 <= n/2 ? 1 : -1;
            int nextY = y + yDir;
            while (nextY >= 0 && nextY < n && !isVisited[nextY][x]){
                matrix[nextY][x] = num++;
                isVisited[nextY][x] = true;
                nextY += yDir;
                isMoved = true;
            }
            y = nextY - yDir;

            if (!isMoved) break;
        }
        return matrix;
    }
};