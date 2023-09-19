class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool dup[100001] = {};

        for (int i=0; i<nums.size(); ++i)
        {
            if (dup[nums[i]])
                return nums[i];
            dup[nums[i]] = true;
        }
        return -1;
    }
};