class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int maxLen = 1;
        int curLen = 1;
        int prevNum = nums[0];

        for (int i=1; i<nums.size(); ++i){
            if (nums[i] > prevNum){
                ++curLen;
                prevNum = nums[i];
            } else {
                maxLen = max(maxLen, curLen);
                curLen = 1;
            }
            prevNum = nums[i];
        }
        maxLen = max(maxLen, curLen);
        return maxLen;
    }
};