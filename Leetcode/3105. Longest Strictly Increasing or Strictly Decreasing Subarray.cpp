class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;

        int longest = nums[0] == nums[1] ? 1 : 2;
        int cur = nums[0] == nums[1] ? 1 : 2;
        bool isIncreasing = nums[0] < nums[1];
        bool isDecreasing = nums[0] > nums[1];

        for (int i=2; i<nums.size(); ++i){
            if (nums[i] > nums[i-1]){
                if (isIncreasing){
                    ++cur;
                } else {
                    isIncreasing = true;
                    isDecreasing = false;
                    cur = 2;
                }
            } else if (nums[i] < nums[i-1]){
                if (isDecreasing){
                    ++cur;
                } else {
                    isIncreasing = false;
                    isDecreasing = true;
                    cur = 2;
                }
            } else {
                cur = 1;
                isIncreasing = false;
                isDecreasing = false;
            }
            longest = max(cur, longest);
        }
        return longest;
    }
};