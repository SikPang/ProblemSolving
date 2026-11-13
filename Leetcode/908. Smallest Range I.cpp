class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        if (nums.size() == 1) return 0;

        sort(nums.begin(), nums.end());

        int minGap = INT_MAX;
        int first = nums[0];
        int last = nums[nums.size()-1] - k;
        for (int i=-k; i<=k; ++i){
            minGap = min(abs(first + i - last), minGap);
        }
        return minGap;
    }
};