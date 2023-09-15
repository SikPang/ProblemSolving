class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); ++i)
        {
            for (int j=0; j<nums.size(); ++j)
            {
                if (i == j)
                    continue;
                if (nums[i] + nums[j] == target)
                    return vector<int>{i, j};
            }
        }
        return vector<int>{-1, -1};
    }
};