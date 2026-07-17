class Solution {
    struct Point{
        int y;
        int x;
        Point(int y, int x) : y(y), x(x) {}
    };

    struct Info{
        Point pos;
        int g;
        int h;

        Info(Point pos, int g, int h) : pos(pos), g(g), h(h) {}

        int GetF() const{
            return g + h;
        }

        bool operator>(const Info& other) const {
            if (GetF() != other.GetF()) {
                return GetF() > other.GetF();
            }
            return h > other.h;
        }
    };

    int GetHeuristic(const Point& cur, const Point& dest){
        return max(abs(cur.x - dest.x), abs(cur.y - dest.y));
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<Point> dir { 
            Point(1, 0), Point(0, 1), Point(1, 1), Point(-1, 0), 
            Point(0, -1), Point(-1, -1), Point(1, -1), Point(-1, 1)
        };
        priority_queue<Info, vector<Info>, greater<Info>> pq;
        vector<vector<int>> gTable(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        Point startPoint = Point(0, 0);
        Point endPoint = Point(grid.size()-1, grid[0].size()-1);
        Info startInfo = Info(startPoint, 1, GetHeuristic(startPoint, endPoint));

        if (grid[0][0] == 0){
            pq.push(startInfo);
            gTable[0][0] = startInfo.g;
        }

        while (!pq.empty()){
            Info cur = pq.top();
            pq.pop();

            if (gTable[cur.pos.y][cur.pos.x] != cur.g) continue;

            if (cur.pos.y == endPoint.y && cur.pos.x == endPoint.x) return cur.g;

            for (int i=0; i<dir.size(); ++i){
                Point next = Point(cur.pos.y + dir[i].y, cur.pos.x + dir[i].x);
                if (next.y < 0 || next.y > endPoint.y || next.x < 0 || next.x > endPoint.x) continue;
                if (grid[next.y][next.x] == 1) continue;
                
                int nextH = GetHeuristic(next, endPoint);
                int nextG = cur.g + 1;
                if (nextG >= gTable[next.y][next.x]) continue;

                pq.push(Info(next, nextG, nextH));
                gTable[next.y][next.x] = nextG;
            }
        }

        return -1;
    }
};