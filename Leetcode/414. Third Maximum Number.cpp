class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> counter(nums.begin(), nums.end());
        if (counter.size() < 3) return *counter.rbegin();
        return *next(counter.rbegin(), 2);
    }
};