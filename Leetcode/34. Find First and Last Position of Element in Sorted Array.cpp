class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator begin = lower_bound(nums.begin(), nums.end(), target);
        if (begin == nums.end() || *begin != target)
             return vector<int>{-1, -1};
        return vector<int>{(int)(distance(nums.begin(), begin)), (int)(distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target) - 1))};
    }
};