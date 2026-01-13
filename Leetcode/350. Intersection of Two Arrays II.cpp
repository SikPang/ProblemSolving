class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> dupChecker;

        for (int i=0; i<nums1.size(); ++i){
            dupChecker[nums1[i]]++;
        }

        for (int i=0; i<nums2.size(); ++i){
            auto iter = dupChecker.find(nums2[i]);
            if (iter != dupChecker.end()){
                iter->second--;
                ret.push_back(iter->first);
                if (iter->second == 0){
                    dupChecker.erase(iter);
                }
            }
        }
        return ret;
    }
};