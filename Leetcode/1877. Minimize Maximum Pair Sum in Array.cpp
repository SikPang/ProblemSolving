class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int max = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            int cur = nums[i] + nums[nums.size()-1-i];
            if (cur > max)
                max = cur;
        }
        return max;
    }
};