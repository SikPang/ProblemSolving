class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int cur = 0;

        for (int i=0; i<nums.size(); ++i){
            if (nums[i] == 1) {
                ++cur;
            } else {
                ret = max(ret, cur);
                cur = 0;
            }
        }
        ret = max(ret, cur);
        return ret;
    }
};