class Solution {
private:
    struct Info {
        int startIdx;
        int height;
        Info(int startIdx, int height) 
            : startIdx(startIdx), height(height) {}
    };

public:
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
};