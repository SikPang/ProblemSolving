class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> ret;
        unordered_set<int> dupChecker(nums1.begin(), nums1.end());

        for (int i=0; i<nums2.size(); ++i){
            if (dupChecker.find(nums2[i]) != dupChecker.end()){
                ret.insert(nums2[i]);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};