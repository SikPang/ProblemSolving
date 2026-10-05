class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int, int>> que;
        vector<vector<bool>> isVisited(image.size(), vector<bool>(image[0].size()));
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        que.push({sr, sc});
        isVisited[sr][sc] = true;
        int targetColor = image[sr][sc];
        image[sr][sc] = color;

        while (!que.empty()){
            pair<int, int> cur = que.front();
            que.pop();

            for (int i=0; i<dir.size(); ++i){
                pair<int, int> next = {cur.first + dir[i].first, cur.second + dir[i].second};

                if (next.first < 0 || next.first >= image.size()
                    || next.second < 0 || next.second >= image[0].size()
                    || isVisited[next.first][next.second]
                    || image[next.first][next.second] != targetColor) continue;

                que.push(next);
                isVisited[next.first][next.second] = true;
                image[next.first][next.second] = color;
            }
        }
        return image;
    }
};