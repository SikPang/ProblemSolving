class Solution {
public:
    int trap(vector<int>& height) {
        int answer = 0;
        int leftH = 0;
        int rightH = 0;

        for (int i=0; i<height.size(); ++i){
            if (height[i] == 0) continue;

            leftH = height[i];
            int j = i+1;
            int secondHeight = 0;
            for (; j<height.size(); ++j){
                secondHeight = max(secondHeight, height[j]);
                if (height[j] >= leftH) {
                    rightH = height[j];
                    break;
                }
            }

            if (j == height.size()) {
                leftH = secondHeight;
                for (j = i+1; j<height.size(); ++j){
                    if (height[j] >= leftH) {
                        rightH = height[j];
                        break;
                    }
                }
            }

            int curH = min(leftH, rightH);
            for (int k=i+1; k<j; ++k){
                answer += curH - height[k];
            }
            i = j - 1;
        }
        return answer;
    }
};