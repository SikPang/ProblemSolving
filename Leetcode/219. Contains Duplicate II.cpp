class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;

        // <value, index>
        vector<pair<int, int>> myNums;
        myNums.reserve(nums.size());
        for (int i=0; i<nums.size(); ++i){
            myNums.push_back(make_pair(nums[i], i));
        }
        sort(myNums.begin(), myNums.end(), [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });

        for (int i=0; i<myNums.size()-1; ++i){
            if (myNums[i].first == myNums[i+1].first && abs(myNums[i].second - myNums[i+1].second) <= k) return true;
        }
        return false;
    }
};