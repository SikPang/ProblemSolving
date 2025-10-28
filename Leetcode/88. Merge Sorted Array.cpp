class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> total;
        int num1Idx = 0;
        int num2Idx = 0;

        total.reserve(m+n);
        while (num1Idx < m || num2Idx < n){
            if (num1Idx == m) total.push_back(nums2[num2Idx++]);
            else if (num2Idx == n) total.push_back(nums1[num1Idx++]);
            else if (nums1[num1Idx] <= nums2[num2Idx]) total.push_back(nums1[num1Idx++]);
            else total.push_back(nums2[num2Idx++]);
        }

        nums1.clear();
        for(int i=0; i<total.size(); ++i){
            nums1.push_back(total[i]);
        }
    }
};