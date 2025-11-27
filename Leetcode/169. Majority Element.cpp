class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int majorElement = nums[0];
        int majorCount = 0;

        int curElement = nums[0];
        int curCount = 0;

        for (int i=1; i<nums.size(); ++i){
            if (curElement == nums[i]){
                ++curCount;
                if (curCount > majorCount){
                    majorElement = curElement;
                    majorCount = curCount;
                }
            } else{
                curElement = nums[i];
                curCount = 1;
            }
        }
        return majorElement;
    }
};