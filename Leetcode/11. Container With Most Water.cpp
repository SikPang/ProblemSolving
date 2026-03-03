class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max = 0;

        while (left < right){
            int area = min(height[left], height[right]) * (right - left);
            max = std::max(area, max);
            if (height[left] > height[right]) {
                --right;
            } else {
                ++left;
            }
        }
        return max;
    }
};