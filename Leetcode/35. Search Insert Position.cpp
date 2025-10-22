class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        if (target <= nums[left]) return 0;
        if (target > nums[right]) return right + 1;

        while (left < right) {
            int center = (right + left) / 2;
            if (left == center || right == center) break;

            if (target == nums[center]){
                return center;
            } else if (target > nums[center]){
                left = center;
            } else {
                right = center;
            }
        }
        return right;
    }
};