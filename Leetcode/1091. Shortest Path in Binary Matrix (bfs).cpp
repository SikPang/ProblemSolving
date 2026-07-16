class Solution {
struct Point{
    int y;
    int x;
    Point(int y, int x) : y(y), x(x) {}
};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<Point> dir { 
            Point(1, 0), Point(0, 1), Point(1, 1), Point(-1, 0), 
            Point(0, -1), Point(-1, -1), Point(1, -1), Point(-1, 1)
        };
        queue<pair<Point, int>> que;
        vector<vector<bool>> isVisited(grid.size(), vector<bool>(grid[0].size()));

        if (grid[0][0] == 0) {
            que.push(make_pair(Point(0, 0), 1));
            isVisited[0][0] = true;
        }

        while (!que.empty()) {
            pair<Point, int> cur = que.front();
            que.pop();

            if (cur.first.y == grid.size()-1 && cur.first.x == grid[0].size()-1) return cur.second;

            for (int i=0; i<dir.size(); ++i){
                Point next = Point(cur.first.y + dir[i].y, cur.first.x + dir[i].x);
                if (next.y < 0 || next.y >= grid.size() || next.x < 0 || next.x >= grid[0].size()) continue;
                if (grid[next.y][next.x] == 1 || isVisited[next.y][next.x]) continue;

                que.push(make_pair(next, cur.second + 1));
                isVisited[next.y][next.x] = true;
            }
        }
        return -1;
    }
};