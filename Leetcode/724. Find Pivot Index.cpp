class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin()+1, nums.end(), 0);

        for (int i=0; i<nums.size(); ++i){
            if (leftSum == rightSum) return i;

            leftSum += nums[i];
            rightSum -= i + 1 == nums.size() ? 0 : nums[i+1];
        }
        return -1;
    }
};