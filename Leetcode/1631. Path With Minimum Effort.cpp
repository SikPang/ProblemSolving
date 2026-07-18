class Solution {
    struct Point {
        int y;
        int x;
        Point (int y, int x) : y(y), x(x) {}
    };

    struct Info {
        Point pos;
        int distance;
        Info (Point pos, int distance) : pos(pos) , distance(distance) {}
        bool operator>(const Info& other) const {
            return distance > other.distance;
        }
    };

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<Point> dir { Point(-1, 0), Point(1, 0), Point(0, 1), Point(0, -1) };
        priority_queue<Info, vector<Info>, greater<Info>> pq;
        vector<vector<int>> table(heights.size(), vector<int>(heights[0].size(), INT_MAX));

        pq.push(Info(Point(0, 0), 0));
        table[0][0] = 0;

        while (!pq.empty()){
            Info cur = pq.top();
            pq.pop();

            if (cur.distance != table[cur.pos.y][cur.pos.x]) continue;
            if (cur.pos.y == heights.size()-1 && cur.pos.x == heights[0].size()-1) return cur.distance;

            for (int i=0; i<dir.size(); ++i){
                Point next = Point(cur.pos.y + dir[i].y, cur.pos.x + dir[i].x);

                if (next.y < 0 || next.y >= heights.size() || next.x < 0 || next.x >= heights[0].size()) continue;

                int diff = abs(heights[cur.pos.y][cur.pos.x] - heights[next.y][next.x]);
                int nextDistance = max(diff, cur.distance);
                if (nextDistance >= table[next.y][next.x]) continue;

                pq.push(Info(next, nextDistance));
                table[next.y][next.x] = nextDistance;
            }
        }
        return -1;
    }
};