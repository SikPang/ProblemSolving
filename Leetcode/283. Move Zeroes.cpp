class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> newNums;
        int zeroCount = 0;

        newNums.reserve(nums.size());
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] == 0){
                ++zeroCount;
            } else{
                newNums.push_back(nums[i]);
            }
        }
        for (int i=0; i<zeroCount; ++i){
            newNums.push_back(0);
        }
        nums.swap(newNums);
    }
};