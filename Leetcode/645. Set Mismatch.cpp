class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int lostNum = 0;
        int addNum = 0;
        int prevNum = nums[0];
        for (int i=1; i<nums.size(); ++i){
            if (nums[i] == nums[i-1]){
                addNum = nums[i];
            } else if (nums[i] - prevNum >= 2) {
                lostNum = nums[i] - 1;
            }
            prevNum = nums[i];
        }
        if (lostNum == 0){
            lostNum = nums[0] == 1 ? nums.size() : 1;
        }
        return vector<int>{addNum, lostNum};
    }
};