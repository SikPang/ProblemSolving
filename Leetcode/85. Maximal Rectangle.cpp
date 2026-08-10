class Solution {
private:
    struct Info {
        int startIdx;
        int height;
        Info(int startIdx, int height) 
            : startIdx(startIdx), height(height) {}
    };

    int largestRectangleArea(vector<int>& heights) {
        stack<Info> stack;
        int maxHeight = 0;

        for (int i=0; i<heights.size(); ++i){
            int startIdx = i;

            while (!stack.empty() && stack.top().height > heights[i]){
                Info info = stack.top();
                stack.pop();

                int curArea = info.height * (i - info.startIdx);
                maxHeight = max(maxHeight, curArea);
                startIdx = info.startIdx;
            }
            stack.push(Info(startIdx, heights[i]));
        }

        while (!stack.empty()){
            Info info = stack.top();
            stack.pop();

            int curArea = info.height * (heights.size() - info.startIdx);
            maxHeight = max(maxHeight, curArea);
        }
        return maxHeight;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> heights(matrix.size(), vector<int>(matrix[0].size()));
        int maxHeight = 0;

        for (int i=0; i<matrix.size(); ++i){
            for (int j=0; j<matrix[i].size(); ++j){
                if (matrix[i][j] == '0') continue;

                heights[i][j] = i > 0 ? heights[i-1][j] + 1 : 1;
            }
            int curHeight = largestRectangleArea(heights[i]);
            maxHeight = max(maxHeight, curHeight);
        }
        return maxHeight;
    }
};