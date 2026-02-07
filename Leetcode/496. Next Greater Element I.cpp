class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> nums2Map;

        ret.reserve(nums1.size());
        for (int i=0; i<nums2.size(); ++i){
            nums2Map.insert(make_pair(nums2[i], i));
        }

        for (int i=0; i<nums1.size(); ++i){
            int num = nums1[i];
            int startIdx = nums2Map[nums1[i]];
            for (int j=startIdx+1; j<nums2.size(); ++j){
                if (nums2[j] > num){
                    ret.push_back(nums2[j]);
                    break;
                }
            }

            if (i+1 != ret.size()){
                ret.push_back(-1);
            }
        }
        return ret;
    }
};