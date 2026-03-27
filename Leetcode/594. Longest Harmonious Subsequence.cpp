class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int longestLength = 0;
        for (int i=0; i<nums.size(); ++i){
            int min = nums[i];
            int last = nums[i];
            int len = 1;
            for (int j=i+1; j<nums.size(); ++j){
                if (nums[j] - min > 1) break;
                ++len;
                last = nums[j];
            }
            if (min == last) continue;
            longestLength = max(longestLength, len);
        }
        return longestLength;
    }
};