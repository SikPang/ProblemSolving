class Solution {
private:
    struct Point{
        int y;
        int x;
        Point(int y, int x) : y(y), x(x) {}
    };

    struct Info{
        Point pos;
        int g;
        Info(Point pos, int g) : pos(pos), g(g) {}
        bool operator>(const Info& other)const{
            return g > other.g;
        }
    };

public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<Info, vector<Info>, greater<Info>> pq;
        vector<vector<int>> gTable(n, vector<int>(m, INT_MAX));
        vector<Point> dir = vector<Point>{Point(1, 0), Point(0, 1)};

        pq.push(Info(Point(0, 0), grid[0][0]));
        gTable[0][0] = grid[0][0];

        while (!pq.empty()){
            Info cur = pq.top();
            pq.pop();

            if (cur.g != gTable[cur.pos.y][cur.pos.x]) continue;
            if (cur.pos.y == n-1 && cur.pos.x == m-1) return cur.g;

            for (int i=0; i<dir.size(); ++i){
                Point next = Point(cur.pos.y + dir[i].y, cur.pos.x + dir[i].x);
                if (next.y >= n || next.x >= m) continue;

                int nextG = cur.g + grid[next.y][next.x];
                if (gTable[next.y][next.x] <= nextG) continue;

                pq.push(Info(next, nextG));
                gTable[next.y][next.x] = nextG;
            }
        }
        return -1;
    }
};