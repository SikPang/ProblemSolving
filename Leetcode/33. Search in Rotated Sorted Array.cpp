class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right){
            int mid = (right - left) / 2.0f + left;

            if (nums[mid] == target) return mid;

            // 좌측 정렬 상태
            if (nums[mid] >= nums[left]) {
                // 타겟이 좌측 안에 있음
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // 우측 정렬 상태
            else {
                // 타겟이 우측 안에 있음
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};